# $NetBSD: Makefile,v 1.16 2008/02/06 15:23:25 rhaen Exp $

DISTNAME=	Event-1.10
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5eve
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/J/JP/JPRIT/}

MAINTAINER=	rhaen@NetBSD.org
COMMENT=	Event library for Perl

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Event/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
