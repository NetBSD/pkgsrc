# $NetBSD: Makefile,v 1.20 2013/05/31 12:40:35 wiz Exp $

DISTNAME=	OLE-Storage_Lite-0.19
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
SVR4_PKGNAME=	p5osl
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=OLE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/OLE-Storage_Lite/
COMMENT=	Module for reading and writing OLE-Structured files

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=		p5-IO-stringy>=2.101:../../devel/p5-IO-stringy

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/OLE/Storage_Lite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
