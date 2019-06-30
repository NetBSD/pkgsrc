# $NetBSD: Makefile,v 1.4 2019/06/30 20:15:37 nia Exp $

DISTNAME=	PerlX-Maybe-1.201
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PerlX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/PerlX-Maybe
COMMENT=	Perl 5 module returning a pair only if they are both defined
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/PerlX/Maybe/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
