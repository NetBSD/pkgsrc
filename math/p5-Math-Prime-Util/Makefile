# $NetBSD: Makefile,v 1.10 2016/02/14 11:44:19 wen Exp $

DISTNAME=	Math-Prime-Util-0.57
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Math-Prime-Util/
COMMENT=	Perl5 utilities related to prime numbers
LICENSE=	${PERL5_LICENSE}

SUBST_CLASSES+=		perl
SUBST_STAGE.perl=	post-patch
SUBST_MESSAGE.perl=	Fixing path to perl
SUBST_FILES.perl+=	bin/factor.pl bin/primes.pl
SUBST_SED.perl=		-e "s|/usr/bin/env perl|${PERL5}|"

USE_LANGUAGES+=	c

DEPENDS+=		p5-Bytes-Random-Secure>=0.23:../../security/p5-Bytes-Random-Secure

PERL5_PACKLIST=		auto/Math/Prime/Util/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
