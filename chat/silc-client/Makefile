# $NetBSD: Makefile,v 1.10 2002/03/29 11:29:22 rh Exp $

DISTNAME=		silc-client-0.8.3
CATEGORIES=		chat
MASTER_SITES=		http://www.silcnet.org/download/client/sources/ \
			ftp://ftp.silcnet.org/silc/client/sources/ \
			http://www.fi.silcnet.org/download/client/sources/ \
			ftp://ftp.au.silcnet.org/pub/silcnet/client/sources/ \
			http://www.us.silcnet.org/download/client/sources/ \
			ftp://ftp.no.silcnet.org/pub/silc/client/sources/ \
			http://www.at.silcnet.org/download/client/sources/
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
CONFIGURE_ARGS+=	--with-etcdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-ncurses=${BUILDLINK_DIR}

# list it into IPv6-ready packages
BUILD_DEFS+=		USE_INET6
CONFIGURE_ARGS+=	--enable-ipv6

# Optional support for perl scripting.
# If you want to disable it, set SILC_CLIENT_WITH_PERL to NO
#
SILC_CLIENT_WITH_PERL?=	YES

.if defined(SILC_CLIENT_WITH_PERL) && ${SILC_CLIENT_WITH_PERL} == YES
CONFIGURE_ARGS+=	--with-perl-lib=${PREFIX}/lib/silc/perl5
CONFIGURE_ARGS+=	--with-simdir=
PLIST_SRC=		${PKGDIR}/PLIST.perl
.include "../../lang/perl5/buildlink.mk"
.else
CONFIGURE_ARGS+=	--with-perl=no
.endif

# If you want to help with testing silc-client, uncomment this
#
#CONFIGURE_ARGS+=	--enable-debug

.if (${MACHINE_ARCH} != "i386")
CONFIGURE_ARGS+=	--disable-asm
.endif

.include "../../devel/ncurses/buildlink.mk"
.include "../../devel/glib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
