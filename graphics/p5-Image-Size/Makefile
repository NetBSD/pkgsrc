# $NetBSD: Makefile,v 1.51 2023/07/06 09:40:39 wiz Exp $

DISTNAME=	Image-Size-3.300
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Image/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Image-Size
COMMENT=	Read the dimensions of an image in several popular formats
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	{perl>=5.9.3,p5-IO-Compress>=2.017}:../../devel/p5-IO-Compress	# Compress::Zlib

#TOOL_DEPENDS+=	{perl>=5.10.0,p5-Test-Simple>=0.80}:../../devel/p5-Test-Simple

PERL5_PACKLIST=		auto/Image/Size/.packlist

REPLACE_PERL+=	imgsize

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
