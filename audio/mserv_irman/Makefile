# $NetBSD: Makefile,v 1.10 2005/07/16 01:19:06 jlam Exp $
#

DISTNAME=	mserv_irman-0.20
CATEGORIES=	audio
MASTER_SITES=	http://www.mono.org/abs/tools/mserv_irman/
EXTRACT_SUFX=   .tbz

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://www.mono.org/abs/tools/mserv_irman/
COMMENT=	Control mserv mp3 jukebox program via infra-red remote

DEPENDS+=	mserv-[0-9]*:../../audio/mserv
DEPENDS+=	libirman>=0.4.1.2nb3:../../sysutils/libirman
DEPENDS+=	p5-Time-HiRes-[0-9]*:../../time/p5-Time-HiRes
DEPENDS+=	p5-Config-IniFiles-[0-9]*:../../devel/p5-Config-IniFiles

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=	perl:run
REPLACE_PERL=	mserv_irman.pl

.include "../../mk/bsd.pkg.mk"
