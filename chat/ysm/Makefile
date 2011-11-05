# $NetBSD: Makefile,v 1.11 2011/11/05 23:21:21 wiz Exp $

DISTNAME=	ysmv7_2_9_9_1
PKGNAME=	ysm-2.9.9.1
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ysmv7/}

MAINTAINER=	dawszy@arhea.net
HOMEPAGE=	http://ysmv7.sourceforge.net/
COMMENT=	The 'You Sick Me' terminal based ICQ client
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_GNU_READLINE=	YES # rl_delete_text

.include "../../devel/readline/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
