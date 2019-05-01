# $NetBSD: Makefile,v 1.22 2019/05/01 07:15:18 wiz Exp $

DISTNAME=	confuse-3.2.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=martinh/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	libconfuse

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://github.org/martinh/libconfuse/
COMMENT=	Configuration file parser library
LICENSE=	isc

BUILD_DEPENDS+=		gettext-m4-[0-9]*:../../devel/gettext-m4
BUILD_DEPENDS+=		gettext-tools-[0-9]*:../../devel/gettext-tools

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-shared
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		pkg-config msgfmt autoconf automake flex

PKGCONFIG_OVERRIDE+=	libconfuse.pc.in
INSTALLATION_DIRS=	lib include

# the included, but generated, lexer.c includes a
# definition of a function which is then not used.
BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
