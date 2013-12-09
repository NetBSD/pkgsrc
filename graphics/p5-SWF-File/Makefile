# $NetBSD: Makefile,v 1.18 2013/12/09 14:17:48 obache Exp $
#

DISTNAME=	SWF-File-0.42
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	graphics www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/Y/YS/YSAS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/SWF-File/
COMMENT=	Manipulating Flash movie (SWF) files

DEPENDS+=	p5-Data-TemporaryBag-[0-9]*:../../devel/p5-Data-TemporaryBag
DEPENDS+=	{perl>=5.9.3,p5-IO-Compress>=2.017}:../../devel/p5-IO-Compress	# Compress::Zlib

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/SWF/File/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
