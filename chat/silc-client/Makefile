# $NetBSD: Makefile,v 1.23 2003/03/17 20:12:18 salo Exp $
#

DISTNAME=		silc-client-0.9.12
CATEGORIES=		chat security
MASTER_SITES=		http://www.silcnet.org/download/client/sources/ \
			ftp://ftp.silcnet.org/silc/client/sources/ \
			http://www.fi.silcnet.org/download/client/sources/ \
			ftp://ftp.au.silcnet.org/pub/silcnet/client/sources/ \
			http://www.at.silcnet.org/download/client/sources/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		salo@netbsd.org
HOMEPAGE=		http://www.silcnet.org/
COMMENT=                Client for the Secure Internet Live Conferencing (SILC) protocol

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
GNU_CONFIGURE=		YES
USE_GMAKE=		YES
USE_GNU_ICONV=		YES
USE_LIBTOOL=		YES
SHLIBTOOL_OVERRIDE=	${WRKSRC}/libtool ${WRKSRC}/irssi/libtool \
			${WRKSRC}/lib/silcmath/mpi/libtool

BUILDLINK_DEPENDS.iconv=	libiconv>=1.7

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR?=	silc

MAKE_ENV+=		examplesdir=${PREFIX}/share/examples/silc

CONF_FILES+=		${PREFIX}/share/examples/silc/silc.conf.default \
			${PKG_SYSCONFDIR}/silc.conf

CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/silc
CONFIGURE_ARGS+=	--with-helpdir=${PREFIX}/share/silc/help
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/silc
CONFIGURE_ARGS+=	--with-etcdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-simdir=${PREFIX}/lib/silc/modules
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-terminfo
CONFIGURE_ARGS+=	--without-libtoolfix

# Use native curses library.
.if (${OPSYS} == "NetBSD") || (${OPSYS} == "SunOS")
CONFIGURE_ARGS+=	--with-vcurses
.elif (${OPSYS} == "Linux") || (${OPSYS} == "Darwin")
CONFIGURE_ARGS+=        --with-ncurses
.endif

# List it into IPv6-ready packages.
BUILD_DEFS+=		USE_INET6
CONFIGURE_ARGS+=	--enable-ipv6

# Optional support for perl scripting.
# If you want to disable it, set SILC_CLIENT_WITH_PERL to NO
# in your /etc/mk.conf
#
SILC_CLIENT_WITH_PERL?=	YES

.if defined(SILC_CLIENT_WITH_PERL) && ${SILC_CLIENT_WITH_PERL} == YES
CONFIGURE_ARGS+=	--with-perl-lib=${PREFIX}/lib/silc/perl5
.include "../../lang/perl5/buildlink2.mk"
PLIST_SRC+=		${PKGDIR}/PLIST.perl
.else
CONFIGURE_ARGS+=	--with-perl=no
.endif

# Assembler optimizations.
#
.if (${MACHINE_ARCH} != "i386")
CONFIGURE_ARGS+=	--disable-asm
.endif

# If you want to debug silc-client, uncomment this.
#
#CONFIGURE_ARGS+=	--enable-debug

PLIST_SRC+=		${PKGDIR}/PLIST

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/glib/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
