# $NetBSD: Makefile,v 1.10 2013/05/31 12:41:57 wiz Exp $

DISTNAME=	String-Random-0.22
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	perl5 security
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=String/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/String-Random/
COMMENT=	Perl module to generate random strings based on a pattern

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_MODULE_TYPE=	Module::Build

PERL5_PACKLIST=	auto/String/Random/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
