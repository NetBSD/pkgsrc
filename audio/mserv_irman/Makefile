# $NetBSD: Makefile,v 1.8 2004/11/06 01:48:51 abs Exp $
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

USE_PERL5=	YES

.include "../../mk/bsd.pkg.mk"
