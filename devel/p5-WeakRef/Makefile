# $NetBSD: Makefile,v 1.18 2012/10/31 11:19:16 asau Exp $

DISTNAME=	WeakRef-0.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
SVR4_PKGNAME=	p5wre
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/LUKKA/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Provide weak references in Perl

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/WeakRef/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
