# $NetBSD: Makefile,v 1.1.1.1 2004/11/06 18:55:04 he Exp $

DISTNAME=	Lingua-EN-Inflect-1.88
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5lei
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Lingua/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~dconway/Lingua-EN-Inflect-1.88/
COMMENT=	Perl module for inflection of english words and a/an selection

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Lingua/EN/Inflect/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
