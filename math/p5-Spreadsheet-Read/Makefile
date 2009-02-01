# $NetBSD: Makefile,v 1.1.1.1 2009/02/01 16:53:27 seb Exp $
#

DISTNAME=	Spreadsheet-Read-0.34
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Spreadsheet/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Spreadsheet-Read/
COMMENT=	Perl 5 module to read the data from a spreadsheet

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Spreadsheet/Read/.packlist
MAKE_ENV+=		AUTOMATED_TESTING=1

# This is useless but placate check-interpreter.mk
REPLACE_PERL+=	Read.pm

DEPENDS+=	p5-Spreadsheet-ParseExcel>=0.26:../../math/p5-Spreadsheet-ParseExcel
DEPENDS+=	p5-Spreadsheet-ReadSXC>=0.20:../../math/p5-Spreadsheet-ReadSXC
DEPENDS+=	p5-Text-CSV_XS>=0.23:../../textproc/p5-Text-CSV_XS
DEPENDS+=	p5-Spreadsheet-XLSX-[0-9]*:../../math/p5-Spreadsheet-XLSX

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
