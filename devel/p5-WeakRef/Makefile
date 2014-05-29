# $NetBSD: Makefile,v 1.20 2014/05/29 23:36:26 wiz Exp $

DISTNAME=	WeakRef-0.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
SVR4_PKGNAME=	p5wre
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/LUKKA/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Provide weak references in Perl

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/WeakRef/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
