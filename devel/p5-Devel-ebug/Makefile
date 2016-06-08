# $NetBSD: Makefile,v 1.12 2016/06/08 19:22:52 wiz Exp $

DISTNAME=	Devel-ebug-0.56
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Devel-ebug/
COMMENT=	Simple, extensible Perl 5 debugger
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Accessor-Chained-[0-9]*:../../devel/p5-Class-Accessor-Chained
DEPENDS+=	p5-Devel-StackTrace-[0-9]*:../../devel/p5-Devel-StackTrace
DEPENDS+=	p5-PadWalker-[0-9]*:../../devel/p5-PadWalker
DEPENDS+=	p5-Proc-Background-[0-9]*:../../devel/p5-Proc-Background
DEPENDS+=	p5-String-Koremutake-[0-9]*:../../textproc/p5-String-Koremutake
DEPENDS+=	p5-YAML-Syck>=0.85:../../textproc/p5-YAML-Syck

# for test target
BUILD_DEPENDS+=	p5-Test-Expect-[0-9]*:../../devel/p5-Test-Expect

USE_LANGUAGES=		# empty
PERL5_MODULE_TYPE=	Module::Install
PERL5_PACKLIST=		auto/Devel/ebug/.packlist
REPLACE_PERL+=	bin/ebug bin/ebug_backend_perl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
