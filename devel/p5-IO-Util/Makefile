# $NetBSD: Makefile,v 1.4 2005/04/11 21:45:32 tv Exp $

DISTNAME=	IO-Util-1.43
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5iou
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/dist/IO-Util/
COMMENT=	Selection of general-utility IO function

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IO/Util/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
