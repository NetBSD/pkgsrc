# $NetBSD: Makefile,v 1.90 2002/12/03 21:21:57 jmmv Exp $

DISTNAME=		mutt-1.4i
PKGNAME=		${DISTNAME:C/i$//}
PKGREVISION=		3
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.mutt.org/pub/mutt/ \
			ftp://ftp.stealth.net/pub/mirrors/ftp.mutt.org/pub/mutt/ \
			ftp://gd.tuwien.ac.at/infosys/mail/mutt/ \
			ftp://ftp.fu-berlin.de/pub/unix/mail/mutt/

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.mutt.org/
COMMENT=		text-based MIME mail client with PGP support

BUILD_USES_MSGFMT=	# defined

USE_BUILDLINK2=		# defined
USE_GMAKE=		# defined
GNU_CONFIGURE=		# defined
USE_PKGLOCALEDIR=	# defined
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR} \
			--with-docdir=${PREFIX}/share/doc/mutt \
			--without-included-gettext \
			--enable-pop --enable-imap

LDFLAGS+=		${_STRIPFLAG_CC}
WRKSRC=			${WRKDIR}/${DISTNAME:C/i$$//}

.include "../../mk/bsd.prefs.mk"

.if ${MUTT_USE_SLANG} == YES
. include "../../devel/libslang/buildlink2.mk"
CONFIGURE_ARGS+=	--with-slang=${BUILDLINK_PREFIX.libslang}
.else
. if ${MUTT_USE_NCURSES} == YES
USE_NCURSES=		# defined
. endif
. include "../../devel/ncurses/buildlink2.mk"
CONFIGURE_ARGS+=	--with-curses=${BUILDLINK_PREFIX.ncurses}
.endif

# There seems to be a problem using NetBSD's /bin/sh, so use /bin/ksh instead.
.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--with-exec-shell=/bin/ksh
.endif

.if ${MUTT_USE_SSL} == YES
.include "../../security/openssl/buildlink2.mk"
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE}
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

.if defined(USE_SASL) && ${USE_SASL} == "YES"
.include "../../security/cyrus-sasl/buildlink2.mk"
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
	${LN} -s ${EGDIR} ${PREFIX}/share/doc/mutt/samples

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
