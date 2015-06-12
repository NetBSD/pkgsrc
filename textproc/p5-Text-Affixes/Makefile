# $NetBSD: Makefile,v 1.6 2015/06/12 10:51:29 wiz Exp $
#

DISTNAME=	Text-Affixes-0.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-Affixes/
COMMENT=	Prefixes and suffixes analysis of text
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Text/Affixes/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
