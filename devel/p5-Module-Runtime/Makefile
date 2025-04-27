# $NetBSD: Makefile,v 1.25 2025/04/27 05:18:52 wiz Exp $

DISTNAME=		Module-Runtime-0.018
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Module-Runtime
COMMENT=		Deal with runtime handling of Perl modules
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Module/Runtime/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
