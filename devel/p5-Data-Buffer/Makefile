# $NetBSD: Makefile,v 1.7 2004/03/20 22:23:19 heinz Exp $
#

DISTNAME=		Data-Buffer-0.04
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5dbu
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=		mcr@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Data-Buffer/
COMMENT=		Perl5 module for low-level binary buffer

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Data/Buffer/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
