# $NetBSD: Makefile,v 1.9 2005/04/11 21:45:35 tv Exp $

DISTNAME=	WeakRef-0.01
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5wre
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/LUKKA/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Provide weak references in Perl

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/WeakRef/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
