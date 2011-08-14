# $NetBSD: Makefile,v 1.4 2011/08/14 13:38:22 obache Exp $
#

DISTNAME=	Math-BaseCnv-1.6.A6FGHKE
PKGNAME=	p5-${DISTNAME:C:\.[^.]*$::}
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/P/PI/PIP/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Math-BaseCnv/
COMMENT=	Fast functions to CoNVert between number Bases
LICENSE=	gnu-gpl-v3

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Math/BaseCnv/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
