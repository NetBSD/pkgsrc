# $NetBSD: Makefile,v 1.8 2004/01/05 22:16:25 jlam Exp $
#

DISTNAME=	File-Temp-0.12
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5fte
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Provides functions for generating temporary files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/File/Temp/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
