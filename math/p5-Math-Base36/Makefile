# $NetBSD: Makefile,v 1.7 2012/10/03 21:56:37 wiz Exp $
#

DISTNAME=	Math-Base36-0.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Math-Base36/
COMMENT=	Perl 5 module to encode and decode base36 strings
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Math/Base36/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
