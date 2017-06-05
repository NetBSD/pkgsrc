# $NetBSD: Makefile,v 1.9 2017/06/05 14:24:47 ryoon Exp $
#

DISTNAME=	Text-Affixes-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-Affixes/
COMMENT=	Prefixes and suffixes analysis of text
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Text/Affixes/.packlist
USE_LANGUAGES=	# none

PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
