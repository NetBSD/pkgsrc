# $NetBSD: Makefile,v 1.1.1.1 2003/03/02 19:33:11 mjl Exp $

DISTNAME=	OLE-Storage_Lite-0.11
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5osl
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/K/KW/KWITKNR/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Module for reading and writing OLE-Structured files

DEPENDS+=	p5-IO-stringy>=2.101:../../devel/p5-IO-stringy

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/OLE/Storage_Lite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
