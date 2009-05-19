# $NetBSD: Makefile,v 1.24 2009/05/19 08:59:17 wiz Exp $
#

DISTNAME=		exiv2-0.18
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		http://www.exiv2.org/

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://www.exiv2.org/
COMMENT=		Image metadata manipulation
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
GCC_REQD+=		3.3

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

USE_PKGLOCALEDIR=	yes

# The visibility feature seems complicated and causes problems on DragonFly
# (reported by Matt Madden) and on Gentoo (http://bugs.gentoo.org/185907).
CONFIGURE_ARGS+=	--disable-visibility

PKGCONFIG_OVERRIDE=	config/exiv2.pc.in

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
