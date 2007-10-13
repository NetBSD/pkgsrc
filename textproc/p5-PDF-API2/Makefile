# $NetBSD: Makefile,v 1.14 2007/10/13 11:57:38 adam Exp $

DISTNAME=	PDF-API2-0.65
PKGNAME=	p5-PDF-API2-0.65
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PDF/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~areibens/PDF-API2-0.65/
COMMENT=	Perl5 module for next generation api for pdf

DEPENDS+=	p5-Compress-Zlib-[0-9]*:../../devel/p5-Compress-Zlib

PERL5_PACKLIST=	auto/PDF/API2/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
