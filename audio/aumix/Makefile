# $NetBSD: Makefile,v 1.7 2001/02/16 13:30:33 wiz Exp $

DISTNAME=	aumix-2.7
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aumix/} \
		http://jpj.net/~trevor/aumix/ \
		${MASTER_SITE_SUNSITE:=apps/sound/mixers/} \
		ftp://aumix.sourceforge.net/pub/aumix/stable/ \
		http://jpj.net/~trevor/aumix/old/

MAINTAINER=	trevor@jpj.net
HOMEPAGE=	http://jpj.net/~trevor/aumix.html
COMMENT=	Set mix levels

BUILD_DEPENDS+=	msgfmt:../../devel/gettext
DEPENDS+=	gtk+-1.2.*:../../x11/gtk

USE_CURSES=	yes
REPLACE_NCURSES=	${WRKSRC}/configure ${WRKSRC}/src/curses.h \
			${WRKSRC}/src/gpm-xterm.h
USE_LIBINTL=	yes

GNU_CONFIGURE=	yes

CONFIGURE_ARGS= --enable-own-labels

.include "../../mk/bsd.prefs.mk"

.if ${NEED_NCURSES} == "YES"
CFLAGS+=        -I${WRKSRC}/src -I${LOCALBASE}/include
.endif

.include "../../mk/bsd.pkg.mk"
