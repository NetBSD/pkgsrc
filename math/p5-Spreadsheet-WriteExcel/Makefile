# $NetBSD: Makefile,v 1.2 2002/10/20 17:46:05 seb Exp $
#

DISTNAME=	Spreadsheet-WriteExcel-0.35
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/J/JM/JMCNAMARA/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Create Excel data files

DEPENDS+=	p5-Parse-RecDescent-*:../../devel/p5-Parse-RecDescent

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Spreadsheet/WriteExcel/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
