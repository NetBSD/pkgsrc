# $NetBSD: Makefile,v 1.1.1.1 2001/11/28 12:11:12 martti Exp $
#

DISTNAME=	PDF-API2-0.2.0.2_dev
PKGNAME=	p5-PDF-API2-0.2.0.2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PDF/}

MAINTAINER=	packages@netbsd.org
#HOMEPAGE=	
COMMENT=	perl5 module for next generation api for pdf

DEPENDS+=	p5-Compress-Zlib-[0-9]*:../../devel/p5-Compress-Zlib

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/PDF/API2/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
