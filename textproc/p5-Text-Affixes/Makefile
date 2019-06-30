# $NetBSD: Makefile,v 1.11 2019/06/30 20:16:58 nia Exp $
#

DISTNAME=	Text-Affixes-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Text-Affixes
COMMENT=	Prefixes and suffixes analysis of text
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Text/Affixes/.packlist
USE_LANGUAGES=	# none

PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
