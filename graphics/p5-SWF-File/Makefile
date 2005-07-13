# $NetBSD: Makefile,v 1.4 2005/07/13 18:01:31 jlam Exp $
#

DISTNAME=	SWF-File-0.22
PKGREVISION=	1
CATEGORIES=	graphics www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/Y/YS/YSAS/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/SWF-File/
COMMENT=	Manipulating Flash movie (SWF) files

DEPENDS+=       p5-Data-TemporaryBag-[0-9]*:../../devel/p5-Data-TemporaryBag

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/SWF/File/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
