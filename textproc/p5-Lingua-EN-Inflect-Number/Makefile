# $NetBSD: Makefile,v 1.14 2019/07/01 21:35:53 nia Exp $
#

DISTNAME=	Lingua-EN-Inflect-Number-1.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=   ${MASTER_SITE_PERL_CPAN:=../../authors/id/N/NE/NEILB/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cpan.metacpan.org/authors/id/S/SI/SIMON/
COMMENT=	Force number of words to singular or plural
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Lingua-EN-Inflect>=0:../../textproc/p5-Lingua-EN-Inflect

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Lingua/EN/Inflect/Number/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
