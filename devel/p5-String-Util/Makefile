# $NetBSD: Makefile,v 1.13 2023/07/06 09:40:02 wiz Exp $

DISTNAME=	String-Util-1.34
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/B/BA/BAKERSCOT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/String::Util
COMMENT=	String processing utilities
LICENSE=	${PERL5_LICENSE}

TEST_DEPENDS+=	p5-Test-Toolbox-[0-9]*:../../devel/p5-Test-Toolbox

PERL5_MODULE_TYPE=	Module::Build::Tiny
PERL5_PACKLIST=		auto/String/Util/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
