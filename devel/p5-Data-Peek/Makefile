# $NetBSD: Makefile,v 1.37 2023/07/06 09:38:56 wiz Exp $

DISTNAME=	Data-Peek-0.52
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Data-Peek
COMMENT=	Perl 5 collection of low-level debug functions
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/Data/Peek/.packlist
MAKE_ENV+=	AUTOMATED_TESTING=1

TEST_DEPENDS+=	p5-Test-Warnings-[0-9]*:../../devel/p5-Test-Warnings

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
