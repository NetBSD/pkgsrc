# $NetBSD: Makefile,v 1.26 2006/01/26 15:33:30 rillig Exp $

DISTNAME=	libidn-0.6.1
CATEGORIES=	devel
MASTER_SITES=	ftp://alpha.gnu.org/pub/gnu/libidn/ \
		http://josefsson.org/libidn/releases/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/libidn/
COMMENT=	Internationalized Domain Names command line tool

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config perl:build
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	libidn.pc.in
TEST_TARGET=		check

INFO_FILES=		libidn.info

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
