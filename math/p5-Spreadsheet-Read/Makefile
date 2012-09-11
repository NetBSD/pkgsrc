# $NetBSD: Makefile,v 1.11 2012/09/11 23:04:29 asau Exp $
#

DISTNAME=	Spreadsheet-Read-0.45
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Spreadsheet/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Spreadsheet-Read/
COMMENT=	Perl 5 module to read the data from a spreadsheet
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Spreadsheet/Read/.packlist
MAKE_ENV+=		AUTOMATED_TESTING=1

# This is useless but placate check-interpreter.mk
REPLACE_PERL+=	Read.pm

DEPENDS+=	{perl>=5.10.1,p5-File-Temp>=0.22}:../../devel/p5-File-Temp
DEPENDS+=	p5-IO-stringy-[0-9]*:../../devel/p5-IO-stringy
DEPENDS+=	p5-Spreadsheet-ParseExcel>=0.57:../../math/p5-Spreadsheet-ParseExcel
DEPENDS+=	p5-Spreadsheet-ReadSXC>=0.20:../../math/p5-Spreadsheet-ReadSXC
DEPENDS+=	p5-Spreadsheet-XLSX>=0.12:../../math/p5-Spreadsheet-XLSX
DEPENDS+=	p5-Text-CSV_XS>=0.73:../../textproc/p5-Text-CSV_XS
DEPENDS+=	p5-Text-CSV>=1.17:../../textproc/p5-Text-CSV

BUILD_DEPENDS+=	p5-Test-NoWarnings-[0-9]*:../../devel/p5-Test-NoWarnings
BUILD_DEPENDS+=	p5-Test-Simple>=0.94:../../devel/p5-Test-Simple

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
