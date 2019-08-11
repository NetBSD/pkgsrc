# $NetBSD: Makefile,v 1.45 2019/08/11 13:23:33 wiz Exp $

DISTNAME=	PDF-API2-2.033
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SS/SSIMMS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/PDF-API2
COMMENT=	Perl5 module for next generation api for pdf
LICENSE=	gnu-lgpl-v2.1

#DEPENDS+=	{perl>=5.9.3,p5-IO-Compress>=2.017}:../../devel/p5-IO-Compress	# Compress::Zlib>=1.0

BUILD_DEPENDS+=	p5-Test-Memory-Cycle>=0:../../devel/p5-Test-Memory-Cycle

DEPENDS+=	p5-Font-TTF>=0:../../fonts/p5-Font-TTF

PERL5_PACKLIST=	auto/PDF/API2/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
