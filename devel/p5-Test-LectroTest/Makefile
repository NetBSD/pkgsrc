# $NetBSD: Makefile,v 1.9 2025/07/04 08:46:49 wiz Exp $

DISTNAME=	Test-LectroTest-0.5001
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TM/TMOERTEL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-LectroTest
COMMENT=	Easy, automatic, specification-based tests
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Test/LectroTest/.packlist
#PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
