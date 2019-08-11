# $NetBSD: Makefile,v 1.39 2019/08/11 13:19:22 wiz Exp $

DISTNAME=	ExtUtils-CBuilder-0.280230
PKGNAME=	p5-${DISTNAME:C/0.([0-9][0-9])([0-9][0-9])([0-9][0-9])/0.\1.\2.\3/}
PKGREVISION=	2
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
