# $NetBSD: Makefile,v 1.27 2026/08/23 07:40:58 wiz Exp $

DISTNAME=	confuse-3.4
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

# as of 3.4, 1 test failure
TEST_TARGET=		check

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
