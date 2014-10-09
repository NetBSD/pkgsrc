# $NetBSD: Makefile,v 1.10 2014/10/09 13:44:46 wiz Exp $
#

DISTNAME=	Tie-Array-Sorted-1.41
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tie/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Tie-Array-Sorted/
COMMENT=	Array which is kept sorted

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Tie/Array/Sorted/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
