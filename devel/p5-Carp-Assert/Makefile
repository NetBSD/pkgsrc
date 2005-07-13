# $NetBSD: Makefile,v 1.5 2005/07/13 18:01:22 jlam Exp $
#

DISTNAME=		Carp-Assert-0.18
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5cpa
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Carp/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/search?dist=Carp-Assert
COMMENT=		Executable comments like the ANSI C library assert.h

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Carp/Assert/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
