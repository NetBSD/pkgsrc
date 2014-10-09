# $NetBSD: Makefile,v 1.12 2014/10/09 14:06:27 wiz Exp $
#

VERS=		0.11
DISTNAME=	Term-ReadPassword-${VERS}
PKGNAME=	p5-Term-ReadPassword-${VERS}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	lyngbol@wheel.dk
HOMEPAGE=	http://search.cpan.org/~phoenix/Term-ReadPassword/
COMMENT=	Asking the user for a password

PERL5_PACKLIST=		auto/Term/ReadPassword/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
