# $NetBSD: Makefile,v 1.17 2016/06/08 19:23:12 wiz Exp $

DISTNAME=	Module-Load-0.32
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-Load/
COMMENT=	Perl5 module to runtime require of both modules and files
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Module/Load/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
