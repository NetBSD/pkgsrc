# $NetBSD: Makefile,v 1.7 2007/02/18 02:23:55 wiz Exp $
#

DISTNAME=	File-Flat-1.00
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Flat/
COMMENT=	Implements a flat file system

BUILD_DEPENDS+=	p5-Test-ClassAPI>=1.02:../../devel/p5-Test-ClassAPI
DEPENDS+=	p5-File-Remove>=0.21:../../sysutils/p5-File-Remove
DEPENDS+=	p5-File-Temp>=0.14:../../devel/p5-File-Temp
DEPENDS+=	p5-File-Copy-Recursive>=0.28:../../sysutils/p5-File-Copy-Recursive
DEPENDS+=	p5-prefork>=0.02:../../devel/p5-prefork
DEPENDS+=	p5-File-Slurp>=9999.04:../../devel/p5-File-Slurp

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/File/Flat/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
