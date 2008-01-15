# $NetBSD: Makefile,v 1.47 2008/01/15 22:43:00 wiz Exp $

DISTNAME=	libidn-1.4
CATEGORIES=	devel
MASTER_SITES=	ftp://alpha.gnu.org/pub/gnu/libidn/ \
		http://josefsson.org/libidn/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/libidn/
COMMENT=	Internationalized Domain Names command line tool

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		makeinfo pkg-config perl:build
TEXINFO_REQD=		4.1
GNU_CONFIGURE=		yes
INFO_FILES=		yes

PKGCONFIG_OVERRIDE+=	libidn.pc.in
TEST_TARGET=		check
#LICENSE=		gnu-gplv3 gnu-gplv2 gnu-lgplv21

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
