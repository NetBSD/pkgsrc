# $NetBSD: Makefile,v 1.5 2003/03/29 12:42:39 jmmv Exp $
#

DISTNAME=	PDF-111
PKGNAME=	p5-PDF-1.11
SVR4_PKGNAME=	p5pdf
WRKSRC=		${WRKDIR}/PDF
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PDF/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.geocities.com/CapeCanaveral/Hangar/4794/
COMMENT=	perl5 module for pdf document manipulation

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/PDF/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
