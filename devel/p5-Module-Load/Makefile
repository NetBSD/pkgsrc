# $NetBSD: Makefile,v 1.21 2019/06/30 20:15:20 nia Exp $

DISTNAME=	Module-Load-0.34
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Module-Load
COMMENT=	Perl5 module to runtime require of both modules and files
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Module/Load/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
