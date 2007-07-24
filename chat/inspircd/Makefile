# $NetBSD: Makefile,v 1.1.1.1 2007/07/24 20:13:19 adrianp Exp $
#

DISTNAME=	InspIRCd-1.1.10
PKGNAME=	${DISTNAME:S/InspIRCd/inspircd/}
CATEGORIES=	chat
MASTER_SITES=	http://www.inspircd.org/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.inspircd.org/
COMMENT=	Modular C++ IRC Daemon

USE_TOOLS+=		perl:build gmake
REPLACE_PERL+=		.inspircd.inc configure

WRKSRC=			${WRKDIR}/${DISTNAME:S/InspIRCd/inspircd/}
HAS_CONFIGURE=		yes
CONFIG_SHELL=		${PERL5}
USE_LANGUAGES=		c++
PLIST_SRC=		${WRKDIR}/.PLIST_SRC
PLIST_SRC+=		${PKGDIR}/PLIST.common_end
RCD_SCRIPTS+=		inspircd
PKG_SYSCONFSUBDIR=	inspircd

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

PKG_USERS_VARS=		INSPIRCD_USER
PKG_GROUPS_VARS=	INSPIRCD_GROUP

PKG_GROUPS=		${INSPIRCD_GROUP:Q}
PKG_USERS=		${INSPIRCD_USER:Q}:${INSPIRCD_GROUP:Q}

PKG_GECOS.${INSPIRCD_USER}=	InspIRCd user

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_FILES.conf=	docs/inspircd.conf.example
SUBST_SED.conf+=	-e "s|/path/to/inspircd.pid|${VARBASE}/run/inspircd/inspircd.pid|g"
SUBST_MESSAGE.conf=	Fixing configuration files.

CONFIGURE_ARGS+=	--disable-interactive
CONFIGURE_ARGS+=	--prefix=${PREFIX}/share/inspircd
CONFIGURE_ARGS+=	--config-dir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--binary-dir=${PREFIX}/bin
CONFIGURE_ARGS+=	--library-dir=${PREFIX}/lib/inspircd
CONFIGURE_ARGS+=	--module-dir=${PREFIX}/share/inspircd/modules

CONFIGURE_ARGS+=	--with-nick-length=${INSP_NICLEN:Q}
CONFIGURE_ARGS+=	--with-channel-length=${INSP_CHANLEN:Q}
CONFIGURE_ARGS+=	--with-max-clients=${INSP_MAXCLI:Q}
CONFIGURE_ARGS+=	--with-ident-length=${INSP_MAXIDENT:Q}
CONFIGURE_ARGS+=	--with-quit-length=${INSP_MAXQUIT:Q}
CONFIGURE_ARGS+=	--with-topic-length=${INSP_MAXTOPIC:Q}
CONFIGURE_ARGS+=	--with-kick-length=${INSP_MAXKICK:Q}
CONFIGURE_ARGS+=	--with-gecos-length=${INSP_MAXGECOS:Q}
CONFIGURE_ARGS+=	--with-away-length=${INSP_MAXAWAY:Q}
CONFIGURE_ARGS+=	--with-max-modes=${INSP_MAXMODES:Q}

.include "options.mk"

BUILD_DEFS+=		INSP_NICLEN INSP_CHANLEN INSPIRCD_USER INSPIRCD_GROUP
BUILD_DEFS+=		INSP_MAXCLI INSP_MAXIDENT INSP_MAXQUIT INSP_MAXTOPIC
BUILD_DEFS+=		INSP_MAXKICK INSP_MAXGECOS INSP_MAXAWAY INSP_MAXMODES
BUILD_DEFS+=		VARBASE

OWN_DIRS_PERMS+=	${VARBASE}/run/inspircd \
			${INSPIRCD_USER:Q} ${INSPIRCD_GROUP:Q} 750

INSPIRCD_USER?=		inspircd
INSPIRCD_GROUP?=	inspircd

# from a default ./configure
INSP_NICLEN?=		31
INSP_CHANLEN?=		64
INSP_MAXCLI?=		64
INSP_MAXIDENT?=		12
INSP_MAXQUIT?=		255
INSP_MAXTOPIC?=		307
INSP_MAXKICK?=		255
INSP_MAXGECOS?=		128
INSP_MAXAWAY?=		200
INSP_MAXMODES?=		20

post-extract:
	${MV} ${WRKDIR}/inspircd ${WRKDIR}/${DISTNAME:S/InspIRCd/inspircd/}

pre-configure:
.if defined(MODULES)
.  for f in ${MODULES}
	${CP} ${EXTRA}/${f} ${WRKSRC}/src/modules/${f}
.  endfor
.endif
.if defined(HEADER)
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

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA_DIR} ${EGDIR}/sql
	${INSTALL_DATA_DIR} ${EGDIR}/aliases

	${INSTALL_DATA} ${WRKSRC}/conf/inspircd.* ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/aliases/*.example ${EGDIR}/aliases
	${INSTALL_DATA} ${WRKSRC}/docs/inspircd.conf.example ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/extras/m_*.sql ${EGDIR}/sql

	${TOUCH} ${VARBASE}/log/inspircd.log
	${CHOWN} ${INSPIRCD_USER}:${INSPIRCD_GROUP} ${VARBASE}/log/inspircd.log
	${CHMOD} 0640 ${VARBASE}/log/inspircd.log

.include "../../mk/bsd.pkg.mk"
