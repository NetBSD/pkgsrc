# $NetBSD: Makefile,v 1.9 2005/07/13 18:01:41 jlam Exp $
#

DISTNAME=	PDF-API2-0.2.0.2_dev
PKGNAME=	p5-PDF-API2-0.2.0.2
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PDF/}

MAINTAINER=	tech-pkg@NetBSD.org
#HOMEPAGE=	
COMMENT=	Perl5 module for next generation api for pdf

DEPENDS+=	p5-Compress-Zlib-[0-9]*:../../devel/p5-Compress-Zlib

PERL5_PACKLIST=	auto/PDF/API2/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
