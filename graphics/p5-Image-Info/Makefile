# $NetBSD: Makefile,v 1.21 2008/04/23 21:12:57 wiz Exp $
#

DISTNAME=	Image-Info-1.28
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5iin
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Image/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Image-Info/
COMMENT=	Perl module to extract meta information from images

DEPENDS+=	p5-IO-String>=1.03:../../devel/p5-IO-String
DEPENDS+=	p5-XML-Simple-[0-9]*:../../textproc/p5-XML-Simple

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Image/Info/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
