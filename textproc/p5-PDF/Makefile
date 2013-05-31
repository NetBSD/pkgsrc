# $NetBSD: Makefile,v 1.22 2013/05/31 12:42:11 wiz Exp $
#

DISTNAME=	PDF-111
PKGNAME=	p5-PDF-1.11
PKGREVISION=	7
SVR4_PKGNAME=	p5pdf
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
