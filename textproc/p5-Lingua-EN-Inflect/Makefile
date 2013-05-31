# $NetBSD: Makefile,v 1.18 2013/05/31 12:42:09 wiz Exp $

DISTNAME=	Lingua-EN-Inflect-1.893
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5lei
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Lingua/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Lingua-EN-Inflect/
COMMENT=	Perl module for inflection of english words and a/an selection
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

REPLACE_PERL+=	demo/demo*.pl

PERL5_PACKLIST=	auto/Lingua/EN/Inflect/.packlist
#PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
