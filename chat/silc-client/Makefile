# $NetBSD: Makefile,v 1.1.1.1 2001/11/29 16:17:43 hubertf Exp $

DISTNAME=		silc-client-0.6.6
CATEGORIES=		chat
MASTER_SITES=		http://ftp.silcnet.org/client/sources/ \
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

.ifndef PKG_SYSCONFSUBDIR
PKG_SYSCONFSUBDIR=	silc
.endif

CONFIGURE_ARGS+=	--with-helpdir=${PREFIX}/share/silc/help \
			--with-docdir=${PREFIX}/share/doc/silc \
			--with-etcdir=${PKG_SYSCONFBASE}/${PKG_SYSCONFSUBDIR}

CONFIGURE_ARGS+=	--with-ncurses=${LOCALBASE}

post-configure:
	cd ${WRKSRC}; \
	${SED} 's/^\(silc_DEPENDENCIES.*\)-L.*buildlink\/lib\(.*\)/\1\2/g' \
	irssi/src/fe-text/Makefile | \
	${SED} 's/^\(silc_DEPENDENCIES.*\)-Wl,-R.*lib\(.*\)/\1\2/g' \
	> Makefile.tmp; \
	${MV} Makefile.tmp irssi/src/fe-text/Makefile

.if (${MACHINE_ARCH} != "i386")
CONFIGURE_ARGS+=	--disable-asm
.endif

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/ncurses/buildlink.mk"
.include "../../devel/glib/buildlink.mk"
.include "../../devel/pth/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
