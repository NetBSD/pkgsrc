# $NetBSD: Makefile,v 1.5 2002/01/14 21:15:59 hubertf Exp $

DISTNAME=		silc-client-0.7.2
CATEGORIES=		chat
MASTER_SITES=		http://silcnet.org/download/client/sources/ \
			ftp://ftp.silcnet.org/silc/client/sources/ \
			http://www.planetmirror.com/pub/silcnet/client/sources/ \
			ftp://ftp.au.silcnet.org/pub/silcnet/client/sources/ \
			http://munitions.vipul.net/software/mirrors/silc/client/sources/ \
			ftp://ftp.no.silcnet.org/pub/silc/client/sources/ \
			http://the.wiretapped.net/security/network-security/silc/client/sources/ \
			ftp://ftp.wiretapped.net/pub/security/network-security/silc/client/sources/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		salo@silcnet.org
HOMEPAGE=		http://www.silcnet.org/
COMMENT=                Client for the Secure Internet Live Conferencing (SILC) protocol

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_NCURSES=		yes
USE_LIBTOOL=		yes
USE_BUILDLINK_ONLY=	yes

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR?=	silc

CONFIGURE_ARGS+=	--with-helpdir=${PREFIX}/share/silc/help
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/silc
CONFIGURE_ARGS+=	--with-etcdir=${PKG_SYSCONFBASE}/${PKG_SYSCONFSUBDIR}
CONFIGURE_ARGS+=	--with-ncurses=${BUILDLINK_DIR}

.if (${MACHINE_ARCH} != "i386")
CONFIGURE_ARGS+=	--disable-asm
.endif

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/ncurses/buildlink.mk"
.include "../../devel/glib/buildlink.mk"
.include "../../devel/pth/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
