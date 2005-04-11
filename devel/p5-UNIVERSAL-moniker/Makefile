# $NetBSD: Makefile,v 1.4 2005/04/11 21:45:35 tv Exp $

DISTNAME=	UNIVERSAL-moniker-0.08
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cdi
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=UNIVERSAL/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/UNIVERSAL-moniker/
COMMENT=	Perl module for assigning user-friendly names to classes

DEPENDS+=	p5-Lingua-EN-Inflect>=1.88:../../devel/p5-Lingua-EN-Inflect

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/UNIVERSAL/moniker/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
