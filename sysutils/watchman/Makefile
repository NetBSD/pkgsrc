# $NetBSD: Makefile,v 1.8 2016/10/29 20:14:42 fhajny Exp $

DISTNAME=	watchman-3.1
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=facebook/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/facebook/watchman/
COMMENT=	Watches files and takes action when they change
LICENSE=	apache-2.0

GITHUB_TAG=	v${PKGVERSION_NOREV}

USE_TOOLS+=	autoconf automake autoreconf gmake
GNU_CONFIGURE=	yes

# https://github.com/facebook/watchman/issues/50
CONFIGURE_ARGS+=	--enable-lenient
CONFIGURE_ARGS+=	--enable-conffile=${PKG_SYSCONFDIR}/watchman.json
CONFIGURE_ARGS+=	--enable-statedir=${VARBASE}/run/watchman
CONFIGURE_ARGS+=	--with-pcre

BUILD_DEFS+=		VARBASE

PLIST_SUBST+=		API_VERSION=${PKGNAME_NOREV}.0

pre-configure:
	cd ${WRKSRC} && ${SH} autogen.sh

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
