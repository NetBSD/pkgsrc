# $NetBSD: Makefile,v 1.13 2005/07/13 18:01:25 jlam Exp $
#

DISTNAME=	File-Temp-0.16
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5fte
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-Temp/
COMMENT=	Provides functions for generating temporary files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/File/Temp/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
