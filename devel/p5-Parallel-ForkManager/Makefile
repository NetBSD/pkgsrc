# $NetBSD: Makefile,v 1.21 2019/06/30 20:15:32 nia Exp $

DISTNAME=	Parallel-ForkManager-2.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Parallel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Parallel-ForkManager
COMMENT=	Simple parallel processing fork manager
LICENSE=	${PERL5_LICENSE}

# for make test
BUILD_DEPENDS+=	p5-Test-Warn-[0-9]*:../../devel/p5-Test-Warn

DEPENDS+=	p5-Moo>=0:../../devel/p5-Moo

PERL5_PACKLIST=		auto/Parallel/ForkManager/.packlist
REPLACE_PERL+=		*/*.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
