# $NetBSD: Makefile,v 1.5 2003/07/21 17:27:38 martti Exp $
#

DISTNAME=	PDF-API2-0.2.0.2_dev
PKGNAME=	p5-PDF-API2-0.2.0.2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PDF/}

MAINTAINER=	tech-pkg@NetBSD.org
#HOMEPAGE=	
COMMENT=	Perl5 module for next generation api for pdf

DEPENDS+=	p5-Compress-Zlib-[0-9]*:../../devel/p5-Compress-Zlib

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/PDF/API2/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
