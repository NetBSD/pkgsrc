# $NetBSD: Makefile,v 1.35 2006/09/03 08:59:13 wiz Exp $

DISTNAME=	libidn-0.6.6
CATEGORIES=	devel
MASTER_SITES=	ftp://alpha.gnu.org/pub/gnu/libidn/ \
		http://josefsson.org/libidn/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/libidn/
COMMENT=	Internationalized Domain Names command line tool

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		makeinfo pkg-config perl:build
GNU_CONFIGURE=		yes
INFO_FILES=		# PLIST

PKGCONFIG_OVERRIDE+=	libidn.pc.in
TEST_TARGET=		check

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
