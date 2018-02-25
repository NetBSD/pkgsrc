# $NetBSD: Makefile,v 1.5 2018/02/25 17:37:49 wiz Exp $

DISTNAME=		Test-API-0.010
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-API/
COMMENT=		Test a list of subroutines provided by a module
LICENSE=		apache-2.0

PERL5_PACKLIST=		auto/Test/API/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
