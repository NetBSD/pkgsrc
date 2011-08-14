# $NetBSD: Makefile,v 1.6 2011/08/14 14:52:52 obache Exp $
#

DISTNAME=	swatch-3.2.1
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=swatch/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://swatch.sourceforge.net/
COMMENT=	Simple log file watcher

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Date-Calc>=0:../../devel/p5-Date-Calc
DEPENDS+=	p5-Date-Manip>=0:../../devel/p5-Date-Manip
DEPENDS+=	p5-File-Tail>=0:../../misc/p5-File-Tail
DEPENDS+=	p5-Time-HiRes>=1.12:../../time/p5-Time-HiRes
DEPENDS+=	p5-TimeDate>=0:../../time/p5-TimeDate

PERL5_PACKLIST=	auto/swatch/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
