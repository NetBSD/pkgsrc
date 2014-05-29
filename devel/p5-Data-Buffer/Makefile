# $NetBSD: Makefile,v 1.19 2014/05/29 23:35:47 wiz Exp $

DISTNAME=	Data-Buffer-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
SVR4_PKGNAME=	p5dbu
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	mcr@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-Buffer/
COMMENT=	Perl5 module for low-level binary buffer

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Data/Buffer/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
