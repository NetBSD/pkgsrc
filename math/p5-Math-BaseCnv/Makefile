# $NetBSD: Makefile,v 1.1.1.1 2008/10/26 19:12:13 abs Exp $
#

DISTNAME=	Math-BaseCnv-1.4.75O6Pbr
PKGNAME=	p5-${DISTNAME:C:[^0-9.][^.]*$::}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/P/PI/PIP/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Math-BaseCnv/
COMMENT=	Fast functions to CoNVert between number Bases

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Math/BaseCnv/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
