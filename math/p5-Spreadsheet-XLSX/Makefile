# $NetBSD: Makefile,v 1.21 2022/06/28 11:34:43 wiz Exp $
#

DISTNAME=	Spreadsheet-XLSX-0.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Spreadsheet/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Spreadsheet-XLSX
COMMENT=	Perl 5 module to read MS Excel 2007 files
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Archive-Zip-[0-9]*:../../archivers/p5-Archive-Zip
DEPENDS+=	p5-Spreadsheet-ParseExcel-[0-9]*:../../math/p5-Spreadsheet-ParseExcel

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV:S/p5-//}
USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Spreadsheet/XLSX/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
