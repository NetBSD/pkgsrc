# $NetBSD: Makefile,v 1.10 2015/07/12 18:56:06 wiz Exp $
#

DISTNAME=	mserv-irman-0.21
PKGREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://mserv-irman.googlecode.com/files/
EXTRACT_SUFX=	.tbz

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://code.google.com/p/mserv-irman/
COMMENT=	Control mserv mp3 jukebox program via infra-red remote

PREV_PKGPATH=	audio/mserv_irman
SUPERSEDES=	mserv_irman-[0-9]*

DEPENDS+=	mserv-[0-9]*:../../audio/mserv
DEPENDS+=	libirman>=0.4.1.2nb3:../../sysutils/libirman
#DEPENDS+=	{perl>=5.7.3,p5-Time-HiRes-[0-9]*}:../../time/p5-Time-HiRes
DEPENDS+=	p5-Config-IniFiles-[0-9]*:../../devel/p5-Config-IniFiles

USE_TOOLS+=	perl:run
REPLACE_PERL=	mserv-irman.pl

.include "../../mk/bsd.pkg.mk"
