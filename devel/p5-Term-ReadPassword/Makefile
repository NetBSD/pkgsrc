# $NetBSD: Makefile,v 1.8 2012/10/31 11:19:01 asau Exp $
#

VERS=		0.11
DISTNAME=	Term-ReadPassword-${VERS}
PKGNAME=	p5-Term-ReadPassword-${VERS}
PKGREVISION=	3
SVR4_PKGNAME=	p5trk
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	lyngbol@wheel.dk
HOMEPAGE=	http://search.cpan.org/~phoenix/Term-ReadPassword/
COMMENT=	Asking the user for a password

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Term/ReadPassword/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
