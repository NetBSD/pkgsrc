# $NetBSD: Makefile,v 1.2 2003/06/02 01:18:26 jschauma Exp $
#

DISTNAME=	Spreadsheet-ParseExcel-0.2602
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/K/KW/KWITKNR/}

MAINTAINER=	tech-pkg@netbsd.org
COMMENT=	Perl module to get information from an Excel file

DEPENDS+=	p5-OLE-Storage_Lite>=0.08:../../devel/p5-OLE-Storage_Lite

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Spreadsheet/ParseExcel/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
