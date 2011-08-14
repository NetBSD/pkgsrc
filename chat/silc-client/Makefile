# $NetBSD: Makefile,v 1.58 2011/08/14 07:38:55 obache Exp $
#

DISTNAME=		${SILC_CLIENT_DISTNAME}
PKGREVISION=		2
CATEGORIES=		chat security
MASTER_SITES=		http://www.silcnet.org/download/client/sources/ \
			ftp://ftp.silcnet.org/silc/client/sources/ \
			ftp://ftp.sunet.se/pub/network/silc/client/sources/
EXTRACT_SUFX=		${SILC_CLIENT_EXTRACT_SUFX}

MAINTAINER=		salo@NetBSD.org
HOMEPAGE=		http://www.silcnet.org/
COMMENT=		Client for the Secure Internet Live Conferencing (SILC) protocol

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"
.include "../../chat/silc-client/Makefile.common"

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake
USE_LIBTOOL=		YES
OVERRIDE_DIRDEPTH=	3
SHLIBTOOL_OVERRIDE=	# empty

PKG_SYSCONFSUBDIR?=	${PKGBASE}

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
MAKE_ENV+=		examplesdir=${EGDIR}

CONF_FILES+=		${EGDIR}/silc.conf.default ${PKG_SYSCONFDIR}/silc.conf

CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/${PKGBASE}
CONFIGURE_ARGS+=	--with-helpdir=${PREFIX}/share/${PKGBASE}/help
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/${PKGBASE}
CONFIGURE_ARGS+=	--with-etcdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-simdir=${PREFIX}/lib/${PKGBASE}/modules
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-terminfo
CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ARGS+=	--without-libtoolfix

# Use native curses library.
.if (${OPSYS} == "NetBSD") || (${OPSYS} == "SunOS")
CONFIGURE_ARGS+=	--with-vcurses
.elif (${OPSYS} == "Linux") || (${OPSYS} == "Darwin")
CONFIGURE_ARGS+=	--with-ncurses
.else
# XXX: Need testing on other operating systems, use safe defaults for now.
CONFIGURE_ARGS+=	--with-ncurses
.endif

# Assembler optimizations.
#
.if (${MACHINE_ARCH} != "i386")
CONFIGURE_ARGS+=	--disable-asm
.endif

.include "options.mk"

PLIST_SRC+=		${PKGDIR}/PLIST
INSTALLATION_DIRS+=	lib/${PKGBASE} libexec/${PKGBASE}/scripts

post-install:
	${INSTALL_DATA} ${WRKSRC}/apps/irssi/config.h ${DESTDIR}${SILC_CLIENT_CONFIG_H}
	${INSTALL_DATA} ${WRKSRC}/apps/irssi/irssi-config ${DESTDIR}${SILC_CLIENT_CONFIG}
.if !empty(PKG_OPTIONS:Mperl)
	${INSTALL_DATA} ${WRKSRC}/apps/irssi/scripts/*.pl	\
	    ${DESTDIR}${PREFIX}/libexec/${PKGBASE}/scripts
# Create PLIST fragment for Perl modules.
#
	@cd ${DESTDIR}${PREFIX} &&						     \
		${FIND} lib/${PKGBASE}/perl5 -type f > ${WRKDIR}/PLIST.perl
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
