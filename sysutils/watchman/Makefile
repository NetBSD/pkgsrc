# $NetBSD: Makefile,v 1.9 2016/11/01 14:54:01 fhajny Exp $

DISTNAME=	watchman-4.7.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=facebook/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://facebook.github.io/watchman/
COMMENT=	Watches files and takes action when they change
LICENSE=	apache-2.0

GITHUB_TAG=	v${PKGVERSION_NOREV}

USE_TOOLS+=	autoconf automake autoreconf gmake
GNU_CONFIGURE=	yes

# As of 4.7.0, SunOS port is broken and unmaintained
# https://github.com/facebook/watchman/issues/322
BROKEN_ON_PLATFORM=	SunOS-*-*

CHECK_PORTABILITY_SKIP+=	travis/run.sh

# https://github.com/facebook/watchman/issues/50
CONFIGURE_ARGS+=	--enable-lenient
CONFIGURE_ARGS+=	--enable-conffile=${PKG_SYSCONFDIR}/watchman.json
CONFIGURE_ARGS+=	--enable-statedir=${VARBASE}/run/watchman
CONFIGURE_ARGS+=	--with-pcre
CONFIGURE_ARGS+=	--without-python

BUILD_DEFS+=		VARBASE

OWN_DIRS+=		${VARBASE}/run/watchman

pre-configure:
	cd ${WRKSRC} && ${SH} autogen.sh

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
