# $NetBSD: Makefile,v 1.6 2015/04/26 05:38:18 mef Exp $

DISTNAME=	watchman-${VERSION}
VERSION=	3.1
MASTER_SITES=	${MASTER_SITE_GITHUB:=facebook/}
GITHUB_PROJECT=	watchman
GITHUB_TAG=	v3.1
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/facebook/watchman/
COMMENT=	Watches files and takes action when they change
LICENSE=	apache-2.0

USE_TOOLS+=	autoconf automake autoreconf gmake
GNU_CONFIGURE=	yes
# https://github.com/facebook/watchman/issues/50
CONFIGURE_ARGS+=	--enable-lenient
CONFIGURE_ARGS+=	--enable-conffile=${PKG_SYSCONFDIR}/watchman.json
CONFIGURE_ARGS+=	--with-pcre

BUILD_DEFS+=		VARBASE

SUBST_CLASSES+=		varbase
SUBST_MESSAGE.varbase=	set WATCHMAN_STATE_DIR to ${VARBASE}/run/watchman
SUBST_STAGE.varbase=	pre-configure
SUBST_FILES.varbase=	configure.ac
SUBST_SED.varbase=	-e '/^WATCHMAN_STATE_DIR/s,\\$$(prefix)/var/,${DESTDIR}${VARBASE}/,'

PLIST_SUBST+=		API_VERSION=${PKGNAME}.0

pre-configure:
	cd ${WRKSRC} && ${SH} autogen.sh

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
