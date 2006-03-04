# $NetBSD: Makefile,v 1.10 2006/03/04 21:30:07 jlam Exp $
#

DISTNAME=	Spreadsheet-ParseExcel-0.2603
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/K/KW/KWITKNR/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Spreadsheet-ParseExcel/
COMMENT=	Perl module to get information from an Excel file

DEPENDS+=	p5-OLE-Storage_Lite>=0.08:../../devel/p5-OLE-Storage_Lite

PERL5_PACKLIST=		auto/Spreadsheet/ParseExcel/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
