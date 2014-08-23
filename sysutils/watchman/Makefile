# $NetBSD: Makefile,v 1.3 2014/08/23 20:13:59 wiz Exp $

DISTNAME=	watchman-${VERSION}
PKGREVISION=	1
VERSION=	2.9.8
CATEGORIES=	sysutils
MASTER_SITES=	-https://github.com/facebook/watchman/archive/v${VERSION}.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/facebook/watchman/
COMMENT=	Watches files and takes action when they change
LICENSE=	apache-2.0

USE_TOOLS+=	autoconf automake autoreconf
GNU_CONFIGURE=	yes
# https://github.com/facebook/watchman/issues/50
CONFIGURE_ARGS+=	--enable-lenient
CONFIGURE_ARGS+=	--enable-conffile=${PKG_SYSCONFDIR}/watchman.json
CONFIGURE_ARGS+=	--with-pcre

pre-configure:
	cd ${WRKSRC} && ${SH} autogen.sh

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
