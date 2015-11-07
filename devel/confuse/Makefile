# $NetBSD: Makefile,v 1.15 2015/11/07 19:31:17 wiz Exp $

DISTNAME=	confuse-2.8
CATEGORIES=	devel
MASTER_SITES=	https://github.com/martinh/
GITHUB_TAG=	v2.8
GITHUB_PROJECT=	libconfuse

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.org/martinh/libconfuse/
COMMENT=	Configuration file parser library
LICENSE=	isc

BUILD_DEPENDS+=		gettext-m4-[0-9]*:../../devel/gettext-m4
BUILD_DEPENDS+=		gettext-tools-[0-9]*:../../devel/gettext-tools

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-shared
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		pkg-config msgfmt autoconf automake

PKGCONFIG_OVERRIDE+=	libconfuse.pc.in
INSTALLATION_DIRS=	lib include

# the included, but generated, lexer.c includes a
# definition of a function which is then not used.
BUILDLINK_TRANSFORM+=	rm:-Werror

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/fetch/github.mk"
.include "../../mk/bsd.pkg.mk"
