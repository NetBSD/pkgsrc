# $NetBSD: Makefile,v 1.4 2011/08/14 12:26:45 obache Exp $
#

DISTNAME=	Tie-Array-Sorted-1.41
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
SVR4_PKGNAME=	p5tas
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tie/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Tie-Array-Sorted/
COMMENT=	An array which is kept sorted

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Tie/Array/Sorted/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
