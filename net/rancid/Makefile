# $NetBSD: Makefile,v 1.1.1.1 2010/03/12 23:39:16 pettai Exp $
#

DISTNAME=		rancid-2.3.2
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.shrubbery.net/pub/rancid/

MAINTAINER=		pettai@NetBSD.org
HOMEPAGE=		http://www.shrubbery.net/rancid/
COMMENT=		Really Awesome New Cisco confIg Differ
LICENSE=		original-bsd

DEPENDS+=		tcl-expect>=5.4:../../lang/tcl-expect

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEFS+=		VARBASE

GNU_CONFIGURE=		yes
USE_TOOLS+=		perl:run

CONFIGURE_ARGS+=	--disable-conf-install
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/rancid
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/doc
CONFIGURE_ENV+=		PERLV_PATH=${PERL5:Q}
CONFIGURE_ENV+=		DIRNAME=${DIRNAME}
CONFIGURE_ENV+=		ID=${ID}

RC_USER?=		rancid
RC_GROUP?=		rancid

PKG_GROUPS=		${RC_GROUP}
PKG_USERS=		${RC_USER}:${RC_GROUP}
PKG_GECOS.${RC_USER}=	Really Awesome New Cisco confIg Differ
PKG_HOME.${RC_USER}=	${VARBASE}/rancid
PKG_SHELL.${RC_USER}=	${SH}
PKG_USERS_VARS+=	RC_USER
PKG_GROUPS_VARS+=	RC_GROUP

EGDIR=			${PREFIX}/share/examples/rancid
PKG_SYSCONFSUBDIR?=	rancid
CONF_FILES_PERMS=	${EGDIR}/lg.conf.sample ${PKG_SYSCONFDIR}/lg.conf \
			${ROOT_USER} ${ROOT_GROUP} 0644
CONF_FILES_PERMS+=	${EGDIR}/rancid.conf.sample ${PKG_SYSCONFDIR}/rancid.conf \
			${ROOT_USER} ${ROOT_GROUP} 0644

MESSAGE_SUBST+=		PREFIX=${PREFIX}
MESSAGE_SUBST+=		RC_USER=${RC_USER}

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKSRC}/etc/lg.conf.sample.in
SUBST_FILES.paths+=	${WRKSRC}/etc/rancid.conf.sample.in
SUBST_STAGE.paths=      post-extract
SUBST_SED.paths=        -e 's,@ENV_PATH@,${PREFIX}/sbin:/bin:/usr/bin:/usr/sbin:/sbin:/usr/local/bin:/usr/local/sbin,'

OWN_DIRS_PERMS+=	${VARBASE}/rancid ${RC_USER} ${RC_GROUP} 0755

INSTALLATION_DIRS=	share/examples/rancid
INSTALLATION_DIRS+=	share/doc/rancid
INSTALLATION_DIRS+=	${VARBASE}/rancid

post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/lg.conf.sample ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/rancid.conf.sample ${DESTDIR}${EGDIR}

.include "../../mk/bsd.pkg.mk"
