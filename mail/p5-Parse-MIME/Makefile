# $NetBSD: Makefile,v 1.5 2018/08/20 13:10:16 wen Exp $

DISTNAME=	Parse-MIME-1.005
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AR/ARISTOTLE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~aristotle/Parse-MIME/
COMMENT=	Parse mime-types, match against media ranges
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-JSON-PP-[0-9]*:../../converters/p5-JSON-PP

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Parse/MIME/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
