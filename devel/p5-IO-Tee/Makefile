# $NetBSD: Makefile,v 1.4 2005/04/11 21:45:32 tv Exp $
#

DISTNAME=	IO-Tee-0.64
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ite
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://search.cpan.org/search?module=IO::Tee
COMMENT=	Multiplex output to multiple output handles

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/IO/Tee/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
