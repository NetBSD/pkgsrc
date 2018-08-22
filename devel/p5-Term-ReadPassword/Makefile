# $NetBSD: Makefile,v 1.16 2018/08/22 09:44:42 wiz Exp $
#

VERS=		0.11
DISTNAME=	Term-ReadPassword-${VERS}
PKGNAME=	p5-Term-ReadPassword-${VERS}
PKGREVISION=	9
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	lyngbol@wheel.dk
HOMEPAGE=	http://search.cpan.org/~phoenix/Term-ReadPassword/
COMMENT=	Asking the user for a password

PERL5_PACKLIST=		auto/Term/ReadPassword/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
