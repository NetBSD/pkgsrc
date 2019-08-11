# $NetBSD: Makefile,v 1.3 2019/08/11 13:20:32 wiz Exp $

DISTNAME=	Test-LectroTest-0.5001
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
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
