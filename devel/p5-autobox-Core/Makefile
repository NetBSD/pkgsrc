# $NetBSD: Makefile,v 1.17 2018/08/22 09:44:55 wiz Exp $

DISTNAME=	autobox-Core-1.33
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=autobox/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/autobox-Core/
COMMENT=	Perl 5 module adding core built-in functions in primitive types
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/autobox/Core/.packlist

DEPENDS+=	p5-autobox>=2.71:../../devel/p5-autobox
DEPENDS+=	p5-Want>=0.26:../../devel/p5-Want

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
