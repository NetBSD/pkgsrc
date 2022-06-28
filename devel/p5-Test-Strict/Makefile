# $NetBSD: Makefile,v 1.8 2022/06/28 11:33:30 wiz Exp $

DISTNAME=	Test-Strict-0.52
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MA/MANWAR/}

MAINTAINER=	pkgsrc-users@pkgsrc.org
HOMEPAGE=	https://metacpan.org/pod/Test::Strict
COMMENT=	Check syntax, presence of use strict; and test coverage
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-IO-stringy-[0-9]*:../../devel/p5-IO-stringy

PERL5_PACKLIST=	auto/Test/Strict/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
