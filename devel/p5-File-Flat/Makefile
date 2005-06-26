# $NetBSD: Makefile,v 1.2 2005/06/26 21:08:25 seb Exp $
#

DISTNAME=	File-Flat-0.95
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Flat/
COMMENT=	Implements a flat file system

BUILD_DEPENDS+=	p5-ExtUtils-AutoInstall>=0.59:../../devel/p5-ExtUtils-AutoInstall
BUILD_DEPENDS+=	p5-Test-ClassAPI>=1.02:../../devel/p5-Test-ClassAPI
DEPENDS+=	p5-File-Remove>=0.21:../../sysutils/p5-File-Remove
DEPENDS+=	p5-File-NCopy>=0.32:../../sysutils/p5-File-NCopy
DEPENDS+=	p5-prefork>=0.02:../../devel/p5-prefork
DEPENDS+=	p5-File-Slurp>=9999.04:../../devel/p5-File-Slurp

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/File/Flat/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
