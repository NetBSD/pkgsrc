# $NetBSD: Makefile,v 1.1 2020/04/19 12:43:24 rillig Exp $

DISTNAME=	Test-Strict-0.47
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://cpan.metacpan.org/authors/id/M/MA/MANWAR/

MAINTAINER=	pkgsrc-users@pkgsrc.org
HOMEPAGE=	https://cpan.metacpan.org/authors/id/M/MA/MANWAR/
COMMENT=	Check syntax, presence of use strict; and test coverage
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-File-Temp>=0.01:../../devel/p5-File-Temp
DEPENDS+=	p5-IO-stringy-[0-9]*:../../devel/p5-IO-stringy

PERL5_PACKLIST=	auto/Test/Strict/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
