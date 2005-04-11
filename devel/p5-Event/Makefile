# $NetBSD: Makefile,v 1.10 2005/04/11 21:45:31 tv Exp $

DISTNAME=	Event-0.83
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5eve
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/J/JP/JPRIT/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Event library for Perl

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Event/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
