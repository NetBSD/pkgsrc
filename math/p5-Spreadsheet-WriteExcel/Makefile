# $NetBSD: Makefile,v 1.7 2004/12/20 11:31:05 grant Exp $
#

DISTNAME=	Spreadsheet-WriteExcel-0.41
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/J/JM/JMCNAMARA/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Create Excel data files

DEPENDS+=	p5-Parse-RecDescent-*:../../devel/p5-Parse-RecDescent
DEPENDS+=	p5-File-Temp-*:../../devel/p5-File-Temp

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Spreadsheet/WriteExcel/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
