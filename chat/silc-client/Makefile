# $NetBSD: Makefile,v 1.30 2003/11/27 12:40:53 salo Exp $
#

DISTNAME=		${SILC_CLIENT_DISTNAME}
CATEGORIES=		chat security
MASTER_SITES=		http://www.silcnet.org/download/client/sources/ \
			ftp://ftp.silcnet.org/silc/client/sources/ \
			http://www.fi.silcnet.org/download/client/sources/ \
			ftp://ftp.au.silcnet.org/pub/silcnet/client/sources/ \
			http://www.at.silcnet.org/download/client/sources/
EXTRACT_SUFX=		${SILC_CLIENT_EXTRACT_SUFX}

MAINTAINER=		salo@NetBSD.org
HOMEPAGE=		http://www.silcnet.org/
COMMENT=                Client for the Secure Internet Live Conferencing (SILC) protocol

.include "../../chat/silc-client/Makefile.common"

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
GNU_CONFIGURE=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
SHLIBTOOL_OVERRIDE=	${WRKSRC}/libtool ${WRKSRC}/irssi/libtool \
			${WRKSRC}/lib/silcmath/mpi/libtool

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

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=		USE_INET6 SILC_CLIENT_WITH_PERL

# Use native curses library.
.if (${OPSYS} == "NetBSD") || (${OPSYS} == "SunOS")
CONFIGURE_ARGS+=	--with-vcurses
.elif (${OPSYS} == "Linux") || (${OPSYS} == "Darwin")
CONFIGURE_ARGS+=        --with-ncurses
.else
# XXX: Need testing on other operating systems, use safe defaults for now.
CONFIGURE_ARGS+=        --with-ncurses
.endif

.if defined(USE_INET6) && !empty(USE_INET6:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--enable-ipv6
.endif

# Optional support for perl scripting.
# If you want to disable it, set SILC_CLIENT_WITH_PERL to NO
# in your /etc/mk.conf

# XXX: perl support is currently broken (bug in perl) so disable it.
#
SILC_CLIENT_WITH_PERL=	NO

.if defined(SILC_CLIENT_WITH_PERL) && !empty(SILC_CLIENT_WITH_PERL:M[Yy][Ee][Ss])
CONFIGURE_ARGS+=	--with-perl-lib=${PREFIX}/lib/silc/perl5
.include "../../lang/perl5/buildlink2.mk"
DEPENDS+=		p5-File-MMagic>=1.20:../../misc/p5-File-MMagic
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

post-install:
	${INSTALL_DATA} ${WRKSRC}/irssi/config.h ${SILC_CLIENT_CONFIG_H}
	${INSTALL_DATA} ${WRKSRC}/irssi/irssi-config ${SILC_CLIENT_CONFIG}

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/glib/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
