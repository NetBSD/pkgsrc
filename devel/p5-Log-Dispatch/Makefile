# $NetBSD: Makefile,v 1.52 2016/06/19 12:16:26 mef Exp $

DISTNAME=	Log-Dispatch-2.56
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Log-Dispatch/
COMMENT=	Perl module for logging messages to multiple outputs
LICENSE=	artistic-2.0

DEPENDS+=	p5-Module-Runtime-[0-9]*:../../devel/p5-Module-Runtime
DEPENDS+=	p5-Devel-GlobalDestruction>=0:../../devel/p5-Devel-GlobalDestruction
DEPENDS+=	p5-Dist-CheckConflicts>=0.02:../../devel/p5-Dist-CheckConflicts
DEPENDS+=	p5-Params-Validate>=1.03:../../devel/p5-Params-Validate
# Sys::Syslog >= 0.25 is in Perl core since 5.10.1

# for make test
BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires

PERL5_PACKLIST=		auto/Log/Dispatch/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
