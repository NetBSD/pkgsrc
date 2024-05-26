# $NetBSD: Makefile,v 1.58 2024/05/26 12:40:36 wen Exp $

DISTNAME=	PDF-API2-2.047
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SS/SSIMMS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/PDF-API2
COMMENT=	Perl5 module for next generation api for pdf
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	p5-Font-TTF-[0-9]*:../../fonts/p5-Font-TTF

TEST_DEPENDS+=	p5-Test-Memory-Cycle-[0-9]*:../../devel/p5-Test-Memory-Cycle
TEST_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception

PERL5_PACKLIST=	auto/PDF/API2/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
