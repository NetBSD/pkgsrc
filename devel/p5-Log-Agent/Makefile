# $NetBSD: Makefile,v 1.7 2005/04/04 09:31:03 wiz Exp $

DISTNAME=	Log-Agent-0.306
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5lag
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Log-Agent/
COMMENT=	General logging framework aimed at reusable modules

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Log/Agent/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
