# $NetBSD: Makefile,v 1.15 2013/05/31 12:40:25 wiz Exp $

DISTNAME=	IO-Util-1.5
PKGNAME=	p5-${DISTNAME}0
PKGREVISION=	5
SVR4_PKGNAME=	p5iou
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/dist/IO-Util/
COMMENT=	Selection of general-utility IO function

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/IO/Util/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
