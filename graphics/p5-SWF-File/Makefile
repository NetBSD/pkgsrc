# $NetBSD: Makefile,v 1.6 2006/03/04 21:29:50 jlam Exp $
#

DISTNAME=	SWF-File-0.22
PKGREVISION=	2
CATEGORIES=	graphics www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/Y/YS/YSAS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/SWF-File/
COMMENT=	Manipulating Flash movie (SWF) files

DEPENDS+=       p5-Data-TemporaryBag-[0-9]*:../../devel/p5-Data-TemporaryBag

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/SWF/File/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
