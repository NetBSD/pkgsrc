# $NetBSD: Makefile,v 1.15 2006/03/04 21:30:48 jlam Exp $
#

DISTNAME=	PDF-111
PKGNAME=	p5-PDF-1.11
SVR4_PKGNAME=	p5pdf
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PDF/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.geocities.com/CapeCanaveral/Hangar/4794/
COMMENT=	Perl5 module for pdf document manipulation

WRKSRC=			${WRKDIR}/PDF
PERL5_PACKLIST=		auto/PDF/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
