# $NetBSD: Makefile,v 1.20 2019/03/08 15:10:33 wen Exp $

DISTNAME=	Module-Load-0.34
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-Load/
COMMENT=	Perl5 module to runtime require of both modules and files
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Module/Load/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
