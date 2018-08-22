# $NetBSD: Makefile,v 1.47 2018/08/22 09:45:16 wiz Exp $

DISTNAME=	Image-Info-1.41
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Image/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Image-Info/
COMMENT=	Perl module to extract meta information from images
LICENSE=	${PERL5_LICENSE}

# missing recommends: Image::Xpm, Image::Xbm
DEPENDS+=	p5-XML-LibXML-[0-9]*:../../textproc/p5-XML-LibXML
#DEPENDS+=	p5-XML-Simple-[0-9]*:../../textproc/p5-XML-Simple

PERL5_PACKLIST=		auto/Image/Info/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
