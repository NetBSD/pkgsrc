# $NetBSD: Makefile,v 1.41 2020/03/21 21:54:02 mef Exp $

DISTNAME=	ExtUtils-CBuilder-0.280234
PKGNAME=	p5-${DISTNAME:C/0.([0-9][0-9])([0-9][0-9])([0-9][0-9])/0.\1.\2.\3/}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=ExtUtils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/ExtUtils-CBuilder
COMMENT=	Perl5 module for compiling and linking C code for Perl modules
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		c c++
PERL5_PACKLIST=		auto/ExtUtils/CBuilder/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
