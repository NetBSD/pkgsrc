# $NetBSD: Makefile,v 1.6 2003/06/02 01:16:35 jschauma Exp $
#

DISTNAME=	PDF-Create-0.01
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5pcr
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PDF/}

MAINTAINER=	tech-pkg@netbsd.org
#HOMEPAGE=	
COMMENT=	perl5 module for creating pdf documents

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/PDF/Create/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
