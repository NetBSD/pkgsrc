# $NetBSD: Makefile,v 1.3 2005/04/11 21:45:30 tv Exp $

DISTNAME=	Clone-0.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Clone/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl module for recursively copying datatypes

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Clone/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
