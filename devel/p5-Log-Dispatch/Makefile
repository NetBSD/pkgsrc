# $NetBSD: Makefile,v 1.58 2017/06/05 14:23:11 ryoon Exp $

DISTNAME=	Log-Dispatch-2.63
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
PKG_REVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Log-Dispatch/
COMMENT=	Perl module for logging messages to multiple outputs
LICENSE=	artistic-2.0

DEPENDS+=	p5-Module-Runtime-[0-9]*:../../devel/p5-Module-Runtime
DEPENDS+=	p5-Devel-GlobalDestruction>=0:../../devel/p5-Devel-GlobalDestruction
DEPENDS+=	p5-Dist-CheckConflicts>=0.02:../../devel/p5-Dist-CheckConflicts
DEPENDS+=	p5-Params-ValidationCompiler-[0-9]*:../../devel/p5-Params-ValidationCompiler
DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean
# Sys::Syslog >= 0.25 is in Perl core since 5.10.1

# for make test
BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
BUILD_DEPENDS+=	p5-Test-Needs-[0-9]*:../../devel/p5-Test-Needs
BUILD_DEPENDS+=	p5-Specio-[0-9]*:../../devel/p5-Specio

PERL5_PACKLIST=		auto/Log/Dispatch/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
