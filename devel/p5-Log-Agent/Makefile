# $NetBSD: Makefile,v 1.8 2005/04/11 21:45:33 tv Exp $

DISTNAME=	Log-Agent-0.306
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5lag
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Log-Agent/
COMMENT=	General logging framework aimed at reusable modules

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Log/Agent/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
