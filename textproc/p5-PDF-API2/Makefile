# $NetBSD: Makefile,v 1.27 2013/01/23 01:30:01 wen Exp $

DISTNAME=	PDF-API2-2.020
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SS/SSIMMS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/PDF-API2/
COMMENT=	Perl5 module for next generation api for pdf
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	p5-IO-Compress>=2.017:../../devel/p5-IO-Compress
DEPENDS+=	p5-Font-TTF>=0:../../fonts/p5-Font-TTF

PERL5_PACKLIST=	auto/PDF/API2/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
