# $NetBSD: Makefile,v 1.108 2001/11/12 17:33:42 frueauf Exp $

DISTNAME=       fetchmail-5.9.5
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.ccil.org/pub/esr/fetchmail/ \
		http://www.tuxedo.org/~esr/fetchmail/ \
		http://sunsite.unc.edu/pub/Linux/system/mail/pop/

MAINTAINER=	frueauf@netbsd.org
HOMEPAGE=	http://www.tuxedo.org/~esr/fetchmail/
COMMENT=	batch mail retrieval/forwarding utility for pop2, pop3, apop, imap

BUILD_DEPENDS+=		autoconf>=2.13:../../devel/autoconf
BUILD_USES_MSGFMT=	yes

USE_BUILDLINK_ONLY=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-hesiod

BUILD_DEFS+=		USE_INET6
CFLAGS+=		${CPPFLAGS}
LDFLAGS+=		${CFLAGS}

.include "../../mk/bsd.prefs.mk"

FETCHMAIL_USE_SSL?=	YES

.if defined(FETCHMAIL_USE_SSL) && ${FETCHMAIL_USE_SSL} == YES
.include "../../security/openssl/buildlink.mk"
#USE_SSL=		yes
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_DIR}
.else
CONFIGURE_ARGS+=	--without-ssl
.else
.endif

BUILD_DEFS+=		FETCHMAIL_USE_SSL

.if defined(KERBEROS)
USE_KERBEROS=		yes
CONFIGURE_ARGS+=	--with-kerberos=yes
.if ${MACHINE_PLATFORM:MNetBSD-1.[0-4]*-i386} == ""
REPLACE_KERBEROS_LIBS=	# defined
.endif
.else
CONFIGURE_ARGS+=	--with-kerberos=no
.endif

.if defined(USE_INET6) && ${USE_INET6} == YES
CONFIGURE_ARGS+=	--enable-inet6
.endif

FDOC=	${PREFIX}/share/doc/fetchmail

post-extract:
	@${RM} -f ${WRKSRC}/intl/libintl.h
.if ${OPSYS} == "NetBSD"
	@${RM} -f ${WRKSRC}/md5.h
.endif
	@${MV} ${WRKSRC}/fetchmail.man ${WRKSRC}/fetchmail.tbl
.if defined(REPLACE_KERBEROS_LIBS)
	cd ${WRKSRC} && \
	for F in configure.in configure; do \
		${SED} -e "s/-lkrb -ldes/-lkrb -ldes -lcom_err -lroken/" \
			$$F > $$F.mod; \
		${MV} -f $$F.mod $$F; \
	done
	${CHMOD} a+x ${WRKSRC}/configure
.endif

pre-configure:
	cd ${WRKSRC}; ${LOCALBASE}/bin/autoreconf --force

post-build:
	tbl ${WRKSRC}/fetchmail.tbl >${WRKSRC}/fetchmail.man

post-install:
	${INSTALL_DATA_DIR} ${FDOC}
	cd ${WRKSRC} && ${INSTALL_DATA} \
	   FAQ NOTES FEATURES README COPYING \
	   fetchmail-FAQ.html fetchmail-features.html \
	   design-notes.html ${FDOC}

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
