# $NetBSD: Makefile,v 1.21 2004/03/11 18:19:08 xtraeme Exp $

DISTNAME=	aumix-2.8
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aumix/} \
		http://jpj.net/~trevor/aumix/ \
		${MASTER_SITE_SUNSITE:=apps/sound/mixers/} \
		ftp://aumix.sourceforge.net/pub/aumix/stable/ \
		http://jpj.net/~trevor/aumix/old/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	trevor@jpj.net
HOMEPAGE=	http://jpj.net/~trevor/aumix.html
COMMENT=	Set mix levels

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-own-labels
CONFIGURE_ARGS+=	--enable-nls
CONFIGURE_ARGS+=	--without-gtk1

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
