# $NetBSD: Makefile,v 1.10 2005/08/06 06:19:12 jlam Exp $

DISTNAME=	Log-Agent-0.306
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5lag
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Log/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Log-Agent/
COMMENT=	General logging framework aimed at reusable modules

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Log/Agent/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
