# $NetBSD: Makefile,v 1.10 2006/03/04 21:29:23 jlam Exp $

DISTNAME=	OLE-Storage_Lite-0.14
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5osl
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/J/JM/JMCNAMARA/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/OLE-Storage_Lite/
COMMENT=	Module for reading and writing OLE-Structured files

DEPENDS+=	p5-IO-stringy>=2.101:../../devel/p5-IO-stringy

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/OLE/Storage_Lite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
