# $NetBSD: Makefile,v 1.4 2018/08/22 09:46:36 wiz Exp $

DISTNAME=	Daemon-Generic-0.85
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	sysutils perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/M/MU/MUIR/modules/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/M/MU/MUIR/modules/
COMMENT=	Framework to provide start/stop/reload for a daemon
LICENSE=        ${PERL5_LICENSE}

DEPENDS+=	p5-File-Flock-[0-9]*:../../devel/p5-File-Flock
DEPENDS+=	p5-Data-Structure-Util-[0-9]*:../../devel/p5-Data-Structure-Util

# TEST_DEPENDS
BUILD_DEPENDS+=	p5-AnyEvent-[0-9]*:../../devel/p5-AnyEvent
BUILD_DEPENDS+=	p5-Eval-LineNumbers-[0-9]*:../../devel/p5-Eval-LineNumbers

PERL5_PACKLIST= auto/Daemon/Generic/.packlist
USE_LANGUAGES=  # none

.include "../../devel/p5-Event/buildlink3.mk"
.include "../../lang/perl5/module.mk"

.include "../../mk/bsd.pkg.mk"
