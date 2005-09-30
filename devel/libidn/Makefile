# $NetBSD: Makefile,v 1.21 2005/09/30 13:16:54 wiz Exp $
#

DISTNAME=		libidn-0.5.19
CATEGORIES=		devel
MASTER_SITES=		ftp://alpha.gnu.org/pub/gnu/libidn/ \
			http://josefsson.org/libidn/releases/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/libidn/
COMMENT=		Internationalized Domain Names command line tool

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
TEST_TARGET=		check
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=    libidn.pc.in

INFO_FILES=		libidn.info

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
