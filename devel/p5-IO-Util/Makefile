# $NetBSD: Makefile,v 1.2 2004/12/20 11:31:01 grant Exp $

DISTNAME=	IO-Util-1.26
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5iou
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/dist/IO-Util/
COMMENT=	Selection of general-utility IO function

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IO/Util/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
