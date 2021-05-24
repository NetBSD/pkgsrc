# $NetBSD: Makefile,v 1.7 2021/05/24 19:51:25 wiz Exp $

DISTNAME=	PerlX-Maybe-1.201
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
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
