# $NetBSD: Makefile,v 1.1 2015/10/07 14:09:10 wen Exp $

DISTNAME=		Test-API-0.005
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
