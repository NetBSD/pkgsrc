# $NetBSD: Makefile,v 1.10 2001/06/19 15:55:08 jlam Exp $

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

BUILD_USES_MSGFMT=	yes

#USE_CURSES=		yes
#USE_LIBINTL=		yes

USE_BUILDLINK_ONLY=	yes
USE_CONFIG_WRAPPER=	yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-own-labels
CONFIGURE_ARGS+=	--enable-nls

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/ncurses/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
