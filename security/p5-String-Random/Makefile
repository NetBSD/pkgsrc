# $NetBSD: Makefile,v 1.1.1.1 2006/08/13 17:44:06 adrianp Exp $

DISTNAME=	String-Random-0.21
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 security
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=String/}

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~steve/${DISTNAME}/
COMMENT=	Perl module to generate random strings based on a pattern

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PERL5_MODULE_TYPE=	Module::Build

PERL5_PACKLIST=	auto/String/Random/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
