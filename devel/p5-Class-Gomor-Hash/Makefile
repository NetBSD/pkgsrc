# $NetBSD: Makefile,v 1.1.1.1 2005/08/13 07:51:32 adrianp Exp $

DISTNAME=	Class-Gomor-Hash-0.22
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	adrianp@NetBSD.org
COMMENT=	Class and object builder, hash version

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Class/Gomor/Hash/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
