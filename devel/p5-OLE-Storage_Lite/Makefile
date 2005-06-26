# $NetBSD: Makefile,v 1.7 2005/06/26 07:59:37 wiz Exp $

DISTNAME=	OLE-Storage_Lite-0.14
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5osl
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/J/JM/JMCNAMARA/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/OLE-Storage_Lite/
COMMENT=	Module for reading and writing OLE-Structured files

DEPENDS+=	p5-IO-stringy>=2.101:../../devel/p5-IO-stringy

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/OLE/Storage_Lite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
