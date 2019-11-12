# $NetBSD: Makefile,v 1.45 2019/11/12 13:58:52 mef Exp $

DISTNAME=	Text-Template-1.58
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Text-Template
COMMENT=	Perl5 library for generating form letters
LICENSE=	artistic AND gnu-gpl-v2

TEST_DEPENDS+=	p5-Test-Warnings-[0-9]*:../../devel/p5-Test-Warnings
TEST_DEPENDS+=	p5-Test-More-UTF8-[0-9]*:../../devel/p5-Test-More-UTF8

PERL5_PACKLIST=		auto/Text/Template/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
