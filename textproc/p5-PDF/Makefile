# $NetBSD: Makefile,v 1.8 2003/07/21 17:27:37 martti Exp $
#

DISTNAME=	PDF-111
PKGNAME=	p5-PDF-1.11
SVR4_PKGNAME=	p5pdf
WRKSRC=		${WRKDIR}/PDF
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PDF/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.geocities.com/CapeCanaveral/Hangar/4794/
COMMENT=	Perl5 module for pdf document manipulation

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/PDF/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
