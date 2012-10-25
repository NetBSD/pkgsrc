# $NetBSD: Makefile,v 1.26 2012/10/25 06:56:15 asau Exp $

DISTNAME=	PDF-API2-2.019
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SS/SSIMMS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/PDF-API2/
COMMENT=	Perl5 module for next generation api for pdf
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	p5-IO-Compress>=2.017:../../devel/p5-IO-Compress

PERL5_PACKLIST=	auto/PDF/API2/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
