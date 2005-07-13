# $NetBSD: Makefile,v 1.10 2005/07/13 18:01:30 jlam Exp $

DISTNAME=	WeakRef-0.01
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5wre
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/LUKKA/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Provide weak references in Perl

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/WeakRef/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
