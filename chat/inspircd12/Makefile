# $NetBSD: Makefile,v 1.22 2014/02/12 23:17:36 tron Exp $
#

DISTNAME=	InspIRCd-1.2.0
PKGNAME=	${DISTNAME:S/InspIRCd/inspircd/}
PKGREVISION=	14
CATEGORIES=	chat
MASTER_SITES=	http://www.inspircd.org/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.inspircd.org/
COMMENT=	Modular C++ IRC Daemon

CONFLICTS+=	inspircd<1.2.0

USE_TOOLS+=		perl:build gmake pkg-config
REPLACE_PERL+=		.inspircd.inc configure make/run-cc.pl

WRKSRC=			${WRKDIR}/${DISTNAME:S/InspIRCd/inspircd/}
HAS_CONFIGURE=		yes
CONFIG_SHELL=		${PERL5}
USE_LANGUAGES=		c++
PLIST_SRC=		${WRKDIR}/.PLIST_SRC
RCD_SCRIPTS+=		inspircd
PKG_SYSCONFSUBDIR=	inspircd
MAKE_FILE=		GNUmakefile

FILES_SUBST+=		INSPIRCD_USER=${INSPIRCD_USER:Q}
FILES_SUBST+=		INSPIRCD_GROUP=${INSPIRCD_GROUP:Q}

.include "../../mk/bsd.prefs.mk"

EGDIR=			${PREFIX}/share/examples/inspircd
EXTRA=			${WRKSRC}/src/modules/extra
MODULES?=		# undef
HEADERS?=		# undef
CONF_FILES_PERMS=	${EGDIR}/inspircd.conf.example \
			${PKG_SYSCONFDIR}/inspircd.conf \
			${INSPIRCD_USER:Q} ${INSPIRCD_GROUP:Q} 0400
CONF_FILES_PERMS+=	${EGDIR}/modules.conf.example \
			${PKG_SYSCONFDIR}/modules.conf \
			${INSPIRCD_USER:Q} ${INSPIRCD_GROUP:Q} 0400

PKG_USERS_VARS=		INSPIRCD_USER
PKG_GROUPS_VARS=	INSPIRCD_GROUP

PKG_GROUPS=		${INSPIRCD_GROUP:Q}
PKG_USERS=		${INSPIRCD_USER:Q}:${INSPIRCD_GROUP:Q}

PKG_GECOS.${INSPIRCD_USER}=	InspIRCd user

CONFIGURE_ARGS+=	--disable-interactive
CONFIGURE_ARGS+=	--prefix=${PREFIX}/share/inspircd
CONFIGURE_ARGS+=	--config-dir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--binary-dir=${PREFIX}/bin
CONFIGURE_ARGS+=	--library-dir=${PREFIX}/lib/inspircd
CONFIGURE_ARGS+=	--module-dir=${PREFIX}/share/inspircd/modules

.include "options.mk"

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_FILES.conf=	conf/inspircd.conf.example
SUBST_SED.conf+=	-e "s|/path/to/inspircd.pid|${VARBASE}/run/inspircd/inspircd.pid|g"
SUBST_MESSAGE.conf=	Fixing configuration files.

SUBST_CLASSES+=		install
SUBST_STAGE.install=	post-configure
SUBST_FILES.install=	GNUmakefile
SUBST_SED.install+=	-e "s|-cp conf|\#-cp conf|g"
SUBST_MESSAGE.install=	Fixing installation files.

BUILD_DEFS+=		INSPIRCD_USER INSPIRCD_GROUP VARBASE

MAKE_DIRS+=		${VARBASE}/log
OWN_DIRS_PERMS+=	${VARBASE}/run/inspircd \
			${INSPIRCD_USER:Q} ${INSPIRCD_GROUP:Q} 750

INSPIRCD_USER?=		inspircd
INSPIRCD_GROUP?=	inspircd

CHECK_BUILTIN.openssl:=yes
.include "../../security/openssl/builtin.mk"
CHECK_BUILTIN.openssl:=no

post-extract:
	${MV} ${WRKDIR}/inspircd ${WRKDIR}/${DISTNAME:S/InspIRCd/inspircd/}
.if !empty(USE_BUILTIN.openssl:M[yY][eE][sS]) && !empty(PKG_OPTIONS:Mssl)
	${CP} ${FILESDIR}/openssl.pc ${WRKSRC}/openssl.pc
SUBST_FILES.conf+=	${WRKSRC}/openssl.pc
SUBST_SED.conf+=	-e "s|@SSLBASE@|${BUILDLINK_PREFIX.openssl}|g"
SUBST_SED.conf+=	-e "s|@SSLVER@|${BUILTIN_VERSION.openssl}|g"
.endif

pre-configure:
.if !empty(USE_BUILTIN.openssl:M[yY][eE][sS]) && !empty(PKG_OPTIONS:Mssl)
	${MKDIR} ${BUILDLINK_DIR}/lib/pkgconfig
	${CP} ${WRKSRC}/openssl.pc ${BUILDLINK_DIR}/lib/pkgconfig
.endif
.if defined(MODULES)
.  for f in ${MODULES}
	${CP} ${EXTRA}/${f} ${WRKSRC}/src/modules/${f}
.  endfor
.endif
.if defined(HEADERS)
.  for f in ${HEADERS}
	${CP} ${EXTRA}/${f} ${WRKSRC}/src/modules/${f}
.  endfor
.endif

post-build:
	${CP} ${PKGDIR}/PLIST ${WRKDIR}/.PLIST_SRC
.if defined(MODULES)
.  for f in ${MODULES}
	${ECHO} share/inspircd/modules/${f} | \
		${SED} -e "s|\\.cpp|\\.so|g" >> ${WRKDIR}/.PLIST_SRC
.  endfor
.endif

INSTALLATION_DIRS+=	bin ${EGDIR}/aliases ${EGDIR}/sql

CONF_FILES_PERMS+=	/dev/null ${VARBASE}/log/inspircd.log \
			${INSPIRCD_USER} ${INSPIRCD_GROUP} 0640

post-install:
	${INSTALL_DATA} ${WRKSRC}/conf/inspircd.* ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/modules.* ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/aliases/*.example ${DESTDIR}${EGDIR}/aliases
	${INSTALL_DATA} ${WRKSRC}/conf/inspircd.conf.example ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/extras/m_*.sql ${DESTDIR}${EGDIR}/sql

.include "../../mk/bsd.pkg.mk"
