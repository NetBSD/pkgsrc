# $NetBSD: Makefile,v 1.1.1.1 2007/01/03 14:02:57 adrianp Exp $

DISTNAME=	Class-Gomor-1.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	adrianp@NetBSD.org
COMMENT=	Another class and object builder

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Class/Gomor/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
