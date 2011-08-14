# $NetBSD: Makefile,v 1.12 2011/08/14 12:26:11 obache Exp $

DISTNAME=	IO-Util-1.5
PKGNAME=	p5-${DISTNAME}0
PKGREVISION=	3
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
