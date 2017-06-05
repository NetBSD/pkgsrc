# $NetBSD: Makefile,v 1.11 2017/06/05 14:24:43 ryoon Exp $

DISTNAME=	PDF-Reuse-Barcode-0.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc print perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/C/CN/CNIGHS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/PDF-Reuse-Barcode/
COMMENT=	Create barcodes for PDF documents with PDF::Reuse
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-PDF-Reuse-[0-9]*:../../textproc/p5-PDF-Reuse
DEPENDS+=	p5-GD-Barcode-[0-9]*:../../graphics/p5-GD-Barcode
DEPENDS+=	p5-Barcode-Code128-[0-9]*:../../graphics/p5-Barcode-Code128

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/PDF/Reuse/Barcode/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
