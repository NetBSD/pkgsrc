# $NetBSD: Makefile,v 1.27 2023/07/06 09:39:48 wiz Exp $

DISTNAME=	Parallel-ForkManager-2.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	parallel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Parallel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Parallel-ForkManager
COMMENT=	Simple parallel processing fork manager
LICENSE=	${PERL5_LICENSE}

# for make test
TOOL_DEPENDS+=	p5-Test-Warn-[0-9]*:../../devel/p5-Test-Warn

DEPENDS+=	p5-Moo>=0:../../devel/p5-Moo

PERL5_PACKLIST=		auto/Parallel/ForkManager/.packlist
REPLACE_PERL+=		*/*.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
