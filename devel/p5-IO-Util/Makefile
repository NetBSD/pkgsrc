# $NetBSD: Makefile,v 1.10 2008/10/19 19:17:56 he Exp $

DISTNAME=	IO-Util-1.5
PKGNAME=	p5-${DISTNAME}0
PKGREVISION=	1
SVR4_PKGNAME=	p5iou
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/dist/IO-Util/
COMMENT=	Selection of general-utility IO function

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/IO/Util/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
