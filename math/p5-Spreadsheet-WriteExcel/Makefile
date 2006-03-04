# $NetBSD: Makefile,v 1.11 2006/03/04 21:30:07 jlam Exp $
#

DISTNAME=	Spreadsheet-WriteExcel-0.41
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/J/JM/JMCNAMARA/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Create Excel data files

DEPENDS+=	p5-Parse-RecDescent-*:../../devel/p5-Parse-RecDescent
DEPENDS+=	p5-File-Temp-*:../../devel/p5-File-Temp

PERL5_PACKLIST=		auto/Spreadsheet/WriteExcel/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
