# $NetBSD: Makefile,v 1.42 2005/12/05 23:55:03 rillig Exp $
#

DISTNAME=		${SILC_CLIENT_DISTNAME}
PKGREVISION=		1
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

USE_PKGINSTALL=		YES
GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake
USE_LIBTOOL=		YES
SHLIBTOOL_OVERRIDE=	libtool */libtool */*/*/libtool

PKG_SYSCONFSUBDIR?=	${PKGBASE}

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
MAKE_ENV+=		examplesdir=${EGDIR:Q}

CONF_FILES+=		${EGDIR}/silc.conf.default ${PKG_SYSCONFDIR}/silc.conf

CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/${PKGBASE}
CONFIGURE_ARGS+=	--with-helpdir=${PREFIX}/share/${PKGBASE}/help
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/${PKGBASE}
CONFIGURE_ARGS+=	--with-etcdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-simdir=${PREFIX}/lib/${PKGBASE}/modules
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_DIR:Q}
CONFIGURE_ARGS+=	--with-terminfo
CONFIGURE_ARGS+=	--without-libtoolfix

.include "../../mk/bsd.prefs.mk"

# Use native curses library.
.if (${OPSYS} == "NetBSD") || (${OPSYS} == "SunOS")
CONFIGURE_ARGS+=	--with-vcurses
.elif (${OPSYS} == "Linux") || (${OPSYS} == "Darwin")
CONFIGURE_ARGS+=        --with-ncurses
.else
# XXX: Need testing on other operating systems, use safe defaults for now.
CONFIGURE_ARGS+=        --with-ncurses
.endif

# Assembler optimizations.
#
.if (${MACHINE_ARCH} != "i386")
CONFIGURE_ARGS+=	--disable-asm
.endif

.include "options.mk"

PLIST_SRC+=		${PKGDIR}/PLIST

post-install:
	${INSTALL_DATA} ${WRKSRC}/irssi/config.h ${SILC_CLIENT_CONFIG_H}
	${INSTALL_DATA} ${WRKSRC}/irssi/irssi-config ${SILC_CLIENT_CONFIG}
.if !empty(PKG_OPTIONS:Mperl)
	${INSTALL_DATA_DIR} ${PREFIX}/libexec/${PKGBASE}/scripts
	${INSTALL_DATA} ${WRKSRC}/irssi/scripts/*.pl	\
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
