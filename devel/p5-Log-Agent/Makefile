# $NetBSD: Makefile,v 1.5 2004/04/25 03:40:06 minskim Exp $

DISTNAME=	Log-Agent-0.303
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5lag
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	General logging framework aimed at reusable modules

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Log/Agent/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
