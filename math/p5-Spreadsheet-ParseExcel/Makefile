# $NetBSD: Makefile,v 1.11 2007/06/10 09:08:49 obache Exp $
#

DISTNAME=	Spreadsheet-ParseExcel-0.32
PKGNAME=	p5-${DISTNAME}00
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Spreadsheet/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Spreadsheet-ParseExcel/
COMMENT=	Perl module to get information from an Excel file

DEPENDS+=	p5-OLE-Storage_Lite>=0.08:../../devel/p5-OLE-Storage_Lite

PERL5_PACKLIST=		auto/Spreadsheet/ParseExcel/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
