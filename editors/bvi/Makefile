# $NetBSD: Makefile,v 1.6 2001/02/16 14:40:49 wiz Exp $
#

DISTNAME=	bvi-1.2.0.src
PKGNAME=	bvi-1.2.0
CATEGORIES=	editors
MASTER_SITES=	http://bvi.linuxave.net/download/

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://bvi.linuxave.net/
COMMENT=	Display-oriented editor for binary files, based on the vi editor

GNU_CONFIGURE=	YES
USE_CURSES=	YES
REPLACE_NCURSES=	${WRKSRC}/configure
MAKE_ENV+=	SHELL=${SH}

WRKSRC=		${WRKDIR}/${PKGNAME}

.include "../../mk/bsd.prefs.mk"

.if ${NEED_NCURSES} == "YES"
CONFIGURE_ENV+=	CFLAGS="-I${LOCALBASE}/include" \
		CPPFLAGS="-I${LOCALBASE}/include"
.endif

.include "../../mk/bsd.pkg.mk"
