# $NetBSD: Makefile,v 1.118 2004/06/02 15:43:09 minskim Exp $

DISTNAME=		mutt-1.4.2.1i
PKGNAME=                ${DISTNAME:C/i$//}
PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.mutt.org/mutt/ \
			ftp://ftp.stealth.net/pub/mirrors/ftp.mutt.org/pub/mutt/ \
			ftp://gd.tuwien.ac.at/infosys/mail/mutt/ \
			ftp://ftp.fu-berlin.de/unix/mail/mutt/

MAINTAINER=		tron@NetBSD.org
HOMEPAGE=		http://www.mutt.org/
COMMENT=		Text-based MIME mail client with PGP support

PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILD_USES_MSGFMT=	yes

WRKSRC=			${WRKDIR}/${DISTNAME:C/i$$//}
USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR} \
			--with-docdir=${PREFIX}/share/doc/mutt \
			--without-included-gettext \
			--enable-pop --enable-imap

LDFLAGS+=		${_STRIPFLAG_CC}
PLIST_SRC=		${WRKDIR}/PLIST

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "SunOS")
CONFIGURE_ARGS+=	--without-wc-funcs
.endif

.if ${MUTT_USE_SLANG} == YES
. include "../../devel/libslang/buildlink3.mk"
CONFIGURE_ARGS+=	--with-slang=${BUILDLINK_PREFIX.libslang}
.else
. if ${MUTT_USE_NCURSES} == YES
USE_NCURSES=		yes
. endif
. include "../../devel/ncurses/buildlink3.mk"
CONFIGURE_ARGS+=	--with-curses=${BUILDLINK_PREFIX.ncurses}
.endif

# There is a problem using NetBSD's /bin/sh under old NetBSD releases,
# so use /bin/ksh there.
.if !empty(MACHINE_PLATFORM:MNetBSD-1.[0-5]*-*)
CONFIGURE_ARGS+=	--with-exec-shell=/bin/ksh
.endif

.if ${MUTT_USE_SSL} == YES
.include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE}
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

.if defined(USE_SASL) && ${USE_SASL} == "YES"
.include "../../security/cyrus-sasl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-sasl=${BUILDLINK_PREFIX.cyrus-sasl}
.endif

BUILD_DEFS+=		MUTT_USE_NCURSES MUTT_USE_SLANG MUTT_USE_SSL USE_SASL

EGDIR=			${PREFIX}/share/examples/mutt
CONF_FILES=		${EGDIR}/Muttrc ${PKG_SYSCONFDIR}/Muttrc
SUPPORT_FILES=		${EGDIR}/mime.types ${PKG_SYSCONFDIR}/mime.types

post-extract:
	${MV} ${WRKSRC}/doc/mutt.man ${WRKSRC}/doc/mutt.man.in

pre-build:
	${SED} -e "s|@PREFIX@|${PREFIX}|g" \
	       -e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g" \
	       < ${WRKSRC}/doc/mutt.man.in > ${WRKSRC}/doc/mutt.man

post-install:
	${RM} -f ${PREFIX}/share/doc/mutt/samples
	${LN} -f -s ${EGDIR} ${PREFIX}/share/doc/mutt/samples
	${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	@if [ -f ${PREFIX}/bin/mutt_dotlock ]; then \
		${ECHO} "bin/mutt_dotlock" >> ${PLIST_SRC}; \
	fi

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
