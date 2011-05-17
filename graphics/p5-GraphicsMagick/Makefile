# $NetBSD: Makefile,v 1.1.1.1 2011/05/17 11:17:24 dmcmahill Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../graphics/GraphicsMagick/Makefile.common"

PKGNAME=	p5-GraphicsMagick-${DISTVERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.graphicsmagick.org/perl.html
COMMENT=	Object-oriented Perl interface to GraphicMagick

DISTINFO_FILE=	${.CURDIR}/../../graphics/GraphicsMagick/distinfo
#FILESDIR=	${.CURDIR}/../../graphics/GraphicsMagick/files
#PATCHDIR=	${.CURDIR}/../../graphics/GraphicsMagick/patches

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-perl=${PERL5:Q}

PERL5_CONFIGURE=	no
PERL5_CONFIGURE_DIRS=	${WRKSRC}/PerlMagick
PERL5_PACKLIST=		auto/Graphics/Magick/.packlist
BUILD_DIRS=		${PERL5_CONFIGURE_DIRS}

post-configure: perl5-configure

BUILDLINK_API_DEPENDS.GraphicsMagick+=	GraphicsMagick>=${DISTVERSION}
.include "../../graphics/GraphicsMagick/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
