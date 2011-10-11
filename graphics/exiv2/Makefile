# $NetBSD: Makefile,v 1.31 2011/10/11 09:55:31 adam Exp $

DISTNAME=	exiv2-0.22
CATEGORIES=	graphics
MASTER_SITES=	http://www.exiv2.org/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.exiv2.org/
COMMENT=	Image metadata manipulation
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GCC_REQD+=		3.3
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
# The visibility feature seems complicated and causes problems on DragonFly
# (reported by Matt Madden) and on Gentoo (http://bugs.gentoo.org/185907).
CONFIGURE_ARGS+=	--disable-visibility

PKGCONFIG_OVERRIDE=	config/exiv2.pc.in

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
