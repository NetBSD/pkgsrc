# $NetBSD: Makefile,v 1.15 2023/09/06 08:24:21 abs Exp $

DISTNAME=	Daemon-Generic-0.85
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MU/MUIR/modules/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Daemon::Generic
COMMENT=	Framework to provide start/stop/reload for a daemon
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-File-Slurp-[0-9]*:../../devel/p5-File-Slurp
DEPENDS+=	p5-File-Flock-[0-9]*:../../devel/p5-File-Flock
DEPENDS+=	p5-Data-Structure-Util-[0-9]*:../../devel/p5-Data-Structure-Util

# TEST_DEPENDS
TOOL_DEPENDS+=	p5-AnyEvent-[0-9]*:../../devel/p5-AnyEvent
TOOL_DEPENDS+=	p5-Eval-LineNumbers-[0-9]*:../../devel/p5-Eval-LineNumbers

PERL5_PACKLIST=	auto/Daemon/Generic/.packlist
USE_LANGUAGES=	# none

.include "../../devel/p5-Event/buildlink3.mk"
.include "../../lang/perl5/module.mk"

.include "../../mk/bsd.pkg.mk"
