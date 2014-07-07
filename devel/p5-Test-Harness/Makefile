# $NetBSD: Makefile,v 1.47 2014/07/07 02:54:27 wen Exp $
#

DISTNAME=	Test-Harness-3.32
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/L/LE/LEONT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-Harness
COMMENT=	Run Perl standard test scripts with statistics
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Test/Harness/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
