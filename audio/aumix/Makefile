# $NetBSD: Makefile,v 1.4 2000/12/31 02:56:58 wiz Exp $

DISTNAME=	aumix-2.7
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aumix/} \
		http://jpj.net/~trevor/aumix/ \
		${MASTER_SITE_SUNSITE:=apps/sound/mixers/} \
		ftp://aumix.sourceforge.net/pub/aumix/stable/ \
		http://jpj.net/~trevor/aumix/old/

MAINTAINER=	trevor@jpj.net
HOMEPAGE=	http://jpj.net/~trevor/aumix.html

BUILD_DEPENDS+=	msgfmt:../../devel/gettext
DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	ncurses>=4.2:../../devel/ncurses

USE_LIBINTL=	yes

CFLAGS+=        -I${WRKSRC}/src -I${LOCALBASE}/include

GNU_CONFIGURE=	yes

CONFIGURE_ARGS= --enable-own-labels

.include "../../mk/bsd.pkg.mk"
