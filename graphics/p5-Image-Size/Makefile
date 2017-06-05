# $NetBSD: Makefile,v 1.43 2017/06/05 14:24:01 ryoon Exp $

DISTNAME=	Image-Size-3.300
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Image/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Image-Size/
COMMENT=	Read the dimensions of an image in several popular formats
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	{perl>=5.9.3,p5-IO-Compress>=2.017}:../../devel/p5-IO-Compress	# Compress::Zlib

#BUILD_DEPENDS+=	{perl>=5.10.0,p5-Test-Simple>=0.80}:../../devel/p5-Test-Simple

PERL5_PACKLIST=		auto/Image/Size/.packlist

REPLACE_PERL+=	imgsize

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
