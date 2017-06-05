# $NetBSD: Makefile,v 1.15 2017/06/05 14:23:23 ryoon Exp $

DISTNAME=	MouseX-Types-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/G/GF/GFUJI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MouseX-Types/
COMMENT=	Perl 5 module to organize Mouse types in libraries
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=	auto/MouseX/Types/.packlist

DEPENDS+=	p5-Mouse>=0.41:../../devel/p5-Mouse

BUILD_DEPENDS+=	p5-Test-Exception>=0:../../devel/p5-Test-Exception

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
