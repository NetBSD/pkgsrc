# $NetBSD: Makefile,v 1.71 2020/04/12 08:28:21 adam Exp $

DISTNAME=	inspircd-2.0.28
PKGREVISION=	3
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=inspircd/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://www.inspircd.org/
COMMENT=	Modular Internet Relay Chat (IRC) server (v2 branch)
LICENSE=	gnu-gpl-v2

EXTRACT_USING=	bsdtar
USE_TOOLS+=	perl pkg-config
USE_LANGUAGES=	c c++
HAS_CONFIGURE=	yes
MAKE_FILE=	BSDmakefile

BUILD_DEFS+=	PKG_SYSCONFDIR

PKG_SYSCONFSUBDIR=	inspircd

CONFIGURE_ARGS+=	--with-cc="${CXX} ${CXXFLAGS} ${LDFLAGS}"
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--module-dir=${PREFIX}/lib/inspircd/modules
CONFIGURE_ARGS+=	--config-dir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--data-dir=${PREFIX}/inspircd/data
CONFIGURE_ARGS+=	--log-dir=${PREFIX}/inspircd/logs
CONFIG_SHELL=		${PERL5}

.include "../../mk/bsd.prefs.mk"

INSPIRCD_USER?=		inspircd
INSPIRCD_GROUP?=	inspircd
PKG_GROUPS=		${INSPIRCD_GROUP}
PKG_USERS=		${INSPIRCD_USER}:${INSPIRCD_GROUP}
PKG_GROUPS_VARS=	INSPIRCD_USER
PKG_USERS_VARS=		INSPIRCD_GROUP

FILES_SUBST+=		INSPIRCD_GROUP=${INSPIRCD_GROUP:Q}
FILES_SUBST+=		INSPIRCD_USER=${INSPIRCD_USER:Q}

OWN_DIRS_PERMS+=	${PREFIX}/inspircd ${INSPIRCD_USER} ${INSPIRCD_GROUP} 0755
OWN_DIRS_PERMS+=	${PREFIX}/inspircd/data ${INSPIRCD_USER} ${INSPIRCD_GROUP} 0755
OWN_DIRS_PERMS+=	${PREFIX}/inspircd/logs ${INSPIRCD_USER} ${INSPIRCD_GROUP} 0755

RCD_SCRIPTS=		inspircd

EGDIR=			${PREFIX}/share/examples/inspircd

CONF_FILES+=		${EGDIR}/motd.txt ${PKG_SYSCONFDIR}/motd.txt
CONF_FILES+=		${EGDIR}/rules.txt ${PKG_SYSCONFDIR}/rules.txt
CONF_FILES+=		${EGDIR}/inspircd.conf ${PKG_SYSCONFDIR}/inspircd.conf
CONF_FILES+=		${EGDIR}/links.conf ${PKG_SYSCONFDIR}/links.conf
CONF_FILES+=		${EGDIR}/modules.conf ${PKG_SYSCONFDIR}/modules.conf
CONF_FILES+=		${EGDIR}/opers.conf ${PKG_SYSCONFDIR}/opers.conf
CONF_FILES+=		${EGDIR}/motd.txt ${PKG_SYSCONFDIR}/motd.txt
CONF_FILES+=		${EGDIR}/rules.txt ${PKG_SYSCONFDIR}/rules.txt

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_MESSAGE.conf=	Set variables in configuration file.
SUBST_FILES.conf+=	conf/inspircd.conf
SUBST_VARS.conf=	PREFIX
SUBST_VARS.conf+=	PKG_SYSCONFDIR

INSTALLATION_DIRS+=	${EGDIR}

.include "options.mk"

post-configure:
.for extra in ${INSPIRCD_EXTRAS}
	cd ${WRKSRC} && ${CONFIGURE_ENV} ${PERL5} ./configure --enable-extras=${extra}
.endfor

post-extract:
	${MKDIR} ${WRKSRC}/conf
	${CP} ${FILESDIR}/*.conf ${WRKSRC}/conf

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/.gdbargs
	${INSTALL_DATA} ${DESTDIR}${PKG_SYSCONFDIR}/examples/motd.txt.example ${DESTDIR}${EGDIR}/motd.txt
	${INSTALL_DATA} ${DESTDIR}${PKG_SYSCONFDIR}/examples/rules.txt.example ${DESTDIR}${EGDIR}/rules.txt
	${RM} -rf ${DESTDIR}${PKG_SYSCONFDIR}/examples
	${INSTALL_DATA} ${WRKSRC}/conf/*.conf ${DESTDIR}${EGDIR}

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
