# $NetBSD: Makefile,v 1.136 2003/11/12 03:39:40 jschauma Exp $

DISTNAME=	fetchmail-6.2.5
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://catb.org/~esr/fetchmail/ \
		http://sunsite.unc.edu/pub/Linux/system/mail/pop/

MAINTAINER=	frueauf@NetBSD.org
HOMEPAGE=	http://catb.org/~esr/fetchmail/
COMMENT=	Batch mail retrieval/forwarding utility for pop2, pop3, apop, imap

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-hesiod
CONFIG_GUESS_OVERRIDE=	${WRKSRC}/config.guess
CONFIG_SUB_OVERRIDE=	${WRKSRC}/config.sub

BUILD_DEFS+=		USE_INET6
LDFLAGS+=		${CFLAGS}

.include "../../mk/bsd.prefs.mk"

FETCHMAIL_USE_SSL?=	YES

.if defined(FETCHMAIL_USE_SSL) && ${FETCHMAIL_USE_SSL} == YES
.  include "../../security/openssl/buildlink2.mk"
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE}
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

BUILD_DEFS+=		FETCHMAIL_USE_SSL

.if defined(KERBEROS)
PKG_USE_KERBEROS=	yes
CONFIGURE_ARGS+=	--with-kerberos=yes
.  if ${MACHINE_PLATFORM:MNetBSD-1.[0-4]*-i386} == ""
REPLACE_KERBEROS_LIBS=	# defined
.  endif
.else
CONFIGURE_ARGS+=	--with-kerberos=no
.endif

.if defined(USE_INET6) && ${USE_INET6} == YES
CONFIGURE_ARGS+=	--enable-inet6
.endif

FDOC=		${PREFIX}/share/doc/fetchmail
RCD_SCRIPTS=	fetchmail

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

post-build:
	tbl ${WRKSRC}/fetchmail.tbl >${WRKSRC}/fetchmail.man

post-install:
	${INSTALL_DATA_DIR} ${FDOC}
	cd ${WRKSRC} && ${INSTALL_DATA} \
	   FAQ NOTES FEATURES README COPYING \
	   fetchmail-FAQ.html fetchmail-features.html \
	   design-notes.html ${FDOC}

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
