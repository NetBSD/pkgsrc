# $NetBSD: Makefile,v 1.2 2004/11/29 14:54:05 wiz Exp $
#

DISTNAME=		Carp-Assert-0.18
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5cpa
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Carp/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		http://search.cpan.org/search?dist=Carp-Assert
COMMENT=		Executable comments like the ANSI C library assert.h

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Carp/Assert/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
