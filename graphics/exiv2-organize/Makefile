# $NetBSD: Makefile,v 1.7 2011/02/15 19:50:53 drochner Exp $

DISTNAME=	exiv2-0.21.1
PKGNAME=	exiv2-organize-0.21.1
CATEGORIES=	graphics
MASTER_SITES=	http://www.exiv2.org/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.exiv2.org/
COMMENT=	Image metadata manipulation

LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	bin

USE_LANGUAGES=		c c++
GCC_REQD+=		3.3

USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

# The visibility feature seems complicated and causes problems on DragonFly
# (reported by Matt Madden) and on Gentoo (http://bugs.gentoo.org/185907).
CONFIGURE_ARGS+=	--disable-visibility

do-build:
	(cd ${WRKSRC}/contrib/organize && ${MAKE_ENV} ${GMAKE})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/contrib/organize/organize \
	 ${DESTDIR}${PREFIX}/bin/exiv2-organize

.include "../../graphics/exiv2/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
