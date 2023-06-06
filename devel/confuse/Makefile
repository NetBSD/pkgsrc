# $NetBSD: Makefile,v 1.25 2023/06/06 12:40:35 riastradh Exp $

DISTNAME=	confuse-3.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=libconfuse/}
GITHUB_PROJECT=	libconfuse
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libconfuse/libconfuse
COMMENT=	Configuration file parser library
LICENSE=	isc

TOOL_DEPENDS+=		gettext-m4-[0-9]*:../../devel/gettext-m4
TOOL_DEPENDS+=		gettext-tools-[0-9]*:../../devel/gettext-tools

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
