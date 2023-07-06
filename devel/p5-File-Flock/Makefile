# $NetBSD: Makefile,v 1.14 2023/07/06 09:39:10 wiz Exp $

DISTNAME=	File-Flock-2014.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MU/MUIR/modules/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/File::Flock
COMMENT=	File::Flock - file locking with flock
LICENSE=	${PERL5_LICENSE}

# for make test
TOOL_DEPENDS+=	p5-Data-Structure-Util-[0-9]*:../../devel/p5-Data-Structure-Util
TOOL_DEPENDS+=	p5-File-Slurp-[0-9]*:../../devel/p5-File-Slurp
TOOL_DEPENDS+=	p5-Test-SharedFork-[0-9]*:../../devel/p5-Test-SharedFork
TOOL_DEPENDS+=	p5-IO-Event-[0-9]*:../../devel/p5-IO-Event
TOOL_DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
TOOL_DEPENDS+=	p5-AnyEvent-[0-9]*:../../devel/p5-AnyEvent

PERL5_PACKLIST=	auto/File/Flock/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
