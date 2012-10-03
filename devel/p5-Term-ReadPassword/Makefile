# $NetBSD: Makefile,v 1.7 2012/10/03 21:55:39 wiz Exp $
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
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Term/ReadPassword/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
