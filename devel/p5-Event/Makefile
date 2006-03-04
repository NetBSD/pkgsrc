# $NetBSD: Makefile,v 1.14 2006/03/04 21:29:20 jlam Exp $

DISTNAME=	Event-1.06
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5eve
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/J/JP/JPRIT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Event library for Perl

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Event/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
