# $NetBSD: Makefile,v 1.1 2012/10/19 07:30:32 sno Exp $

DISTNAME=	Math-Prime-Util-0.11
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Math-Prime-Util/
COMMENT=	Perl5 utilities related to prime numbers
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES+=	c

PERL5_PACKLIST=		auto/Math/Prime/Util/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
