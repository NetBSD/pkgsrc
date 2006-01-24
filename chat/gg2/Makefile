# $NetBSD: Makefile,v 1.16 2006/01/24 07:31:57 wiz Exp $

DISTNAME=	gg2-2.2.8
PKGREVISION=	2
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ggadu/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://ggadu.sourceforge.net/
COMMENT=	Instant messenger software for Poland; Jabber plugin included

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
LIBS+=			-lm
PKGCONFIG_OVERRIDE+=	lib/gg2_core.pc.in

CONFIGURE_ARGS+=	--with-external-libgadu
CONFIGURE_ARGS+=	--without-arts
CONFIGURE_ARGS+=	--without-external
CONFIGURE_ARGS+=	--without-gtkspell
CONFIGURE_ARGS+=	--without-remote
CONFIGURE_ARGS+=	--without-update

.include "../../audio/esound/buildlink3.mk"
.include "../../chat/ekg/buildlink3.mk"
.include "../../chat/libtlen/buildlink3.mk"
.include "../../chat/loudmouth/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/xosd/buildlink3.mk"

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
