# $NetBSD: Makefile,v 1.4 2005/04/11 21:45:33 tv Exp $

DISTNAME=	Lingua-EN-Inflect-1.88
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5lei
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Lingua/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Lingua-EN-Inflect/
COMMENT=	Perl module for inflection of english words and a/an selection

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Lingua/EN/Inflect/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
