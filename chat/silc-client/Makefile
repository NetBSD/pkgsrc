# $NetBSD: Makefile,v 1.53 2009/06/05 22:17:08 zafer Exp $
#

DISTNAME=		${SILC_CLIENT_DISTNAME}
PKGREVISION=		1
CATEGORIES=		chat security
MASTER_SITES=		http://www.silcnet.org/download/client/sources/ \
			ftp://ftp.silcnet.org/silc/client/sources/ \
			ftp://ftp.sunet.se/pub/network/silc/client/sources/
EXTRACT_SUFX=		${SILC_CLIENT_EXTRACT_SUFX}

MAINTAINER=		salo@NetBSD.org
HOMEPAGE=		http://www.silcnet.org/
COMMENT=		Client for the Secure Internet Live Conferencing (SILC) protocol

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
INSTALLATION_DIRS+=	${PREFIX}/libexec/${PKGBASE}/scripts

post-install:
	${INSTALL_DATA} ${WRKSRC}/apps/irssi/config.h ${SILC_CLIENT_CONFIG_H}
	${INSTALL_DATA} ${WRKSRC}/apps/irssi/irssi-config ${SILC_CLIENT_CONFIG}
.if !empty(PKG_OPTIONS:Mperl)
	${INSTALL_DATA} ${WRKSRC}/apps/irssi/scripts/*.pl	\
		${PREFIX}/libexec/${PKGBASE}/scripts
# Create PLIST fragment for Perl modules.
#
	@cd ${PREFIX} &&						     \
		(							     \
		${FIND} lib/${PKGBASE}/perl5 -type f > ${WRKDIR}/PLIST.perl; \
		${FIND} lib/${PKGBASE}/perl5 -type d | ${SORT} -r |	     \
			${SED} 's,^,@dirrm ,g' >> ${WRKDIR}/PLIST.perl	     \
		)
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
