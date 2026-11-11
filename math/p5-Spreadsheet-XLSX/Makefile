# $NetBSD: Makefile,v 1.26.2.1 2026/11/11 10:13:17 maya Exp $

DISTNAME=	Spreadsheet-XLSX-0.19
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AS/ASB/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Spreadsheet-XLSX
COMMENT=	Perl 5 module to read MS Excel 2007 files
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Archive-Zip-[0-9]*:../../archivers/p5-Archive-Zip
DEPENDS+=	p5-Spreadsheet-ParseExcel-[0-9]*:../../math/p5-Spreadsheet-ParseExcel
TEST_DEPENDS+=	p5-Test-NoWarnings-[0-9]*:../../devel/p5-Test-NoWarnings

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV:S/p5-//}
USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Spreadsheet/XLSX/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
