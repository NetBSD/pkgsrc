# $NetBSD: Makefile,v 1.2 2003/06/02 01:20:24 jschauma Exp $

DISTNAME=	OLE-Storage_Lite-0.11
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5osl
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/K/KW/KWITKNR/}

MAINTAINER=	tech-pkg@netbsd.org
COMMENT=	Module for reading and writing OLE-Structured files

DEPENDS+=	p5-IO-stringy>=2.101:../../devel/p5-IO-stringy

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/OLE/Storage_Lite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
