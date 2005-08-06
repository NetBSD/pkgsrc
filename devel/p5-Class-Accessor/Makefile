# $NetBSD: Makefile,v 1.6 2005/08/06 06:19:08 jlam Exp $
#

DISTNAME=	Class-Accessor-0.19
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5cac
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/dist/Class-Accessor/
COMMENT=	Automated accessor generation

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=	auto/Class/Accessor/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
