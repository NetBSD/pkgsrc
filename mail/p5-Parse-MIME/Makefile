# $NetBSD: Makefile,v 1.3 2017/06/05 14:24:08 ryoon Exp $

DISTNAME=	Parse-MIME-1.003
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AR/ARISTOTLE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~aristotle/Parse-MIME/
COMMENT=	Parse mime-types, match against media ranges
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-JSON-XS-[0-9]*:../../converters/p5-JSON-XS

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Parse/MIME/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
