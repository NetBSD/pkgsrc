# $NetBSD: Makefile,v 1.7 2005/01/14 08:57:50 adam Exp $

DISTNAME=	gg2-2.2.4
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ggadu/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://ggadu.sourceforge.net/
COMMENT=	Instant messenger software for Poland; Jabber plugin included

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_GNU_TOOLS+=		make
PKGCONFIG_OVERRIDE+=	lib/gg2_core.pc.in
GNU_CONFIGURE=		yes
LIBS+=			-lm

CONFIGURE_ARGS+=	--without-gtkspell --without-remote \
			--without-update --without-external --without-arts \
			--with-external-libgadu

.include "../../audio/esound/buildlink3.mk"
.include "../../chat/ekg/buildlink3.mk"
.include "../../chat/libtlen/buildlink3.mk"
.include "../../chat/loudmouth/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/xosd/buildlink3.mk"

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
