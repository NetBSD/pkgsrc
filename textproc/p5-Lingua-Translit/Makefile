# $NetBSD: Makefile,v 1.8 2022/06/28 11:36:19 wiz Exp $

DISTNAME=	Lingua-Translit-0.28
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AL/ALINKE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Lingua-Translit
COMMENT=	Transliterates text between writing systems
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# none

PERL5_PACKLIST=		auto/Lingua/Translit/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
