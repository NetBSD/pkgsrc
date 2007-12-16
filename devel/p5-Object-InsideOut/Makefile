# $NetBSD: Makefile,v 1.2 2007/12/16 21:57:26 seb Exp $
#

DISTNAME=	Object-InsideOut-3.34
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Object/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Object-InsideOut/
COMMENT=	Perl 5 module providing comprehensive inside-out object support

DEPENDS+=	p5-Exception-Class>=1.22:../../devel/p5-Exception-Class
DEPENDS+=	p5-Want>=0.12:../../devel/p5-Want

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Object/InsideOut/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
