# $NetBSD: Makefile,v 1.43 2015/01/18 12:24:46 wen Exp $

DISTNAME=	Log-Dispatch-2.44
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Log-Dispatch/
COMMENT=	Perl module for logging messages to multiple outputs
LICENSE=	artistic-2.0

DEPENDS+=	p5-Module-Runtime-[0-9]*:../../devel/p5-Module-Runtime
DEPENDS+=	p5-Devel-GlobalDestruction>=0:../../devel/p5-Devel-GlobalDestruction
DEPENDS+=	p5-Dist-CheckConflicts>=0.02:../../devel/p5-Dist-CheckConflicts
DEPENDS+=	p5-Params-Validate>=0.15:../../devel/p5-Params-Validate
# Sys::Syslog >= 0.25 is in Perl core since 5.10.1

PERL5_PACKLIST=		auto/Log/Dispatch/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
