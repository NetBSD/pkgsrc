# $NetBSD: Makefile,v 1.6 2005/04/11 21:45:33 tv Exp $

DISTNAME=	OLE-Storage_Lite-0.11
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5osl
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/K/KW/KWITKNR/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Module for reading and writing OLE-Structured files

DEPENDS+=	p5-IO-stringy>=2.101:../../devel/p5-IO-stringy

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/OLE/Storage_Lite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
