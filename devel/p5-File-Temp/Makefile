# $NetBSD: Makefile,v 1.4 2002/10/13 22:22:49 seb Exp $
#

DISTNAME=	File-Temp-0.12
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5fte
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	packages@netbsd.org
COMMENT=	provides functions for generating temporary files

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/File/Temp/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
