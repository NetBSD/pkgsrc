# $NetBSD: Makefile,v 1.5 2006/06/05 18:39:24 minskim Exp $

DISTNAME=	Lingua-EN-Inflect-1.88
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5lei
PKGREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Lingua/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Lingua-EN-Inflect/
COMMENT=	Perl module for inflection of english words and a/an selection

PKG_INSTALLATION_TYPES=	overwrite pkgviews

REPLACE_PERL+=	demo*.pl

PERL5_PACKLIST=	auto/Lingua/EN/Inflect/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
