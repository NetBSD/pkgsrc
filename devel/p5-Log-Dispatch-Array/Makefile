# $NetBSD: Makefile,v 1.14 2019/08/11 13:19:44 wiz Exp $

DISTNAME=		Log-Dispatch-Array-1.003
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		6
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Log-Dispatch-Array
COMMENT=		Perl 5 module to log events to an array
LICENSE=		${PERL5_LICENSE}

DEPENDS+=	p5-Log-Dispatch-[0-9]*:../../devel/p5-Log-Dispatch

# for make test
BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
BUILD_DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean
BUILD_DEPENDS+=	p5-Specio-[0-9]*:../../devel/p5-Specio
BUILD_DEPENDS+=	p5-Params-ValidationCompiler-[0-9]*:../../devel/p5-Params-ValidationCompiler

PERL5_PACKLIST=		auto/Log/Dispatch/Array/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
