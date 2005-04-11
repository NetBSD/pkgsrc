# $NetBSD: Makefile,v 1.4 2005/04/11 21:45:29 tv Exp $
#

DISTNAME=	Class-Accessor-0.19
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cac
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/dist/Class-Accessor/
COMMENT=	Automated accessor generation

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Class/Accessor/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
