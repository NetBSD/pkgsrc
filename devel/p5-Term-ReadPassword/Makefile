# $NetBSD: Makefile,v 1.20 2021/05/24 19:51:38 wiz Exp $
#

VERS=		0.11
DISTNAME=	Term-ReadPassword-${VERS}
PKGNAME=	p5-Term-ReadPassword-${VERS}
PKGREVISION=	12
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	lyngbol@wheel.dk
HOMEPAGE=	https://metacpan.org/release/Term-ReadPassword
COMMENT=	Asking the user for a password

PERL5_PACKLIST=		auto/Term/ReadPassword/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
