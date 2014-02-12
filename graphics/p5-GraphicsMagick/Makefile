# $NetBSD: Makefile,v 1.20 2014/02/12 23:18:03 tron Exp $

.include "../../graphics/GraphicsMagick/Makefile.common"

PKGNAME=	p5-GraphicsMagick-${DISTVERSION}
PKGREVISION=	1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.graphicsmagick.org/perl.html
COMMENT=	Object-oriented Perl interface to GraphicMagick
LICENSE=	mit

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-perl=${PERL5:Q}

PERL5_CONFIGURE=	no
PERL5_CONFIGURE_DIRS=	${WRKSRC}/PerlMagick
PERL5_PACKLIST=		auto/Graphics/Magick/.packlist
BUILD_DIRS=		${PERL5_CONFIGURE_DIRS}

post-configure: perl5-configure

SUBST_CLASSES+=		libdir
SUBST_STAGE.libdir=	pre-configure
SUBST_SED.libdir=	-e 's|@MAGICKLIBDIR@|${BUILDLINK_PREFIX.GraphicsMagick}/lib ${COMPILER_RPATH_FLAG}${BUILDLINK_PREFIX.GraphicsMagick}/lib|g'
SUBST_FILES.libdir=	PerlMagick/Makefile.PL.in

BUILDLINK_API_DEPENDS.GraphicsMagick+=	GraphicsMagick>=${DISTVERSION}
.include "../../graphics/GraphicsMagick/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
