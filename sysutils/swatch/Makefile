# $NetBSD: Makefile,v 1.9 2012/12/16 17:55:24 wiz Exp $
#

DISTNAME=	swatch-3.2.1
PKGREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=swatch/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/swatch/
COMMENT=	Simple log file watcher
LICENSE=	gnu-gpl-v2 # or later

DEPENDS+=	p5-Date-Calc>=0:../../devel/p5-Date-Calc
DEPENDS+=	p5-Date-Manip>=0:../../devel/p5-Date-Manip
DEPENDS+=	p5-File-Tail>=0:../../misc/p5-File-Tail
DEPENDS+=	p5-Time-HiRes>=1.12:../../time/p5-Time-HiRes
DEPENDS+=	p5-TimeDate>=0:../../time/p5-TimeDate

PERL5_PACKLIST=	auto/swatch/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
