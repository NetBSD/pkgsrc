# $NetBSD: Makefile,v 1.2 2004/12/20 11:30:58 grant Exp $
#

DISTNAME=	Class-Fields-0.201
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5clf
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/dist/Class-Fields/
COMMENT=	Set of modules to operate with class fields and members access

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Class/Fields/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
