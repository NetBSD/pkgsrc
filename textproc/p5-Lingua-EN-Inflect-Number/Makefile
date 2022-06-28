# $NetBSD: Makefile,v 1.20 2022/06/28 11:36:17 wiz Exp $

DISTNAME=	Lingua-EN-Inflect-Number-1.12
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/N/NE/NEILB/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Lingua::EN::Inflect::Number
COMMENT=	Force number of words to singular or plural
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Lingua-EN-Inflect>=0:../../textproc/p5-Lingua-EN-Inflect

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Lingua/EN/Inflect/Number/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
