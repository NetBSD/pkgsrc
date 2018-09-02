# $NetBSD: Makefile,v 1.23 2018/09/02 07:29:32 wiz Exp $

DISTNAME=	Math-Prime-Util-0.71
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Math-Prime-Util/
COMMENT=	Perl5 utilities related to prime numbers
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Bytes-Random-Secure>=0.23:../../security/p5-Bytes-Random-Secure

REPLACE_PERL+=	bin/factor.pl bin/primes.pl
PERL5_PACKLIST=	auto/Math/Prime/Util/.packlist

USE_LANGUAGES+=	c

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
