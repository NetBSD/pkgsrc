# $NetBSD: Makefile,v 1.2 2001/10/18 15:20:41 veego Exp $
#

DISTNAME=	PDF-111
PKGNAME=	p5-PDF-1.11
SVR4_PKGNAME=	p5pdf
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PDF/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.geocities.com/CapeCanaveral/Hangar/4794/
COMMENT=	perl5 module for pdf document manipulation

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/PDF/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

WRKSRC=		${WRKDIR}/PDF

.include "../../mk/bsd.pkg.mk"
