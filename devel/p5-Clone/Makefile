# $NetBSD: Makefile,v 1.5 2005/07/21 08:24:05 abs Exp $

DISTNAME=	Clone-0.18
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Clone/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl module for recursively copying datatypes

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Clone/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
