# $NetBSD: Makefile,v 1.94 2001/05/14 12:12:47 tron Exp $
#

DISTNAME=       fetchmail-5.8.3
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.ccil.org/pub/esr/fetchmail/ \
		http://www.tuxedo.org/~esr/fetchmail/ \
		http://sunsite.unc.edu/pub/Linux/system/mail/pop/

MAINTAINER=	frueauf@netbsd.org
HOMEPAGE=	http://www.tuxedo.org/~esr/fetchmail/
COMMENT=	batch mail retrieval/forwarding utility for pop2, pop3, apop, imap

BUILD_DEPENDS+=	autoconf-2.13:../../devel/autoconf
BUILD_USES_MSGFMT=	yes

USE_LIBINTL=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS+=--without-hesiod
CONFIGURE_ENV+=  LDFLAGS="${CFLAGS}"

BUILD_DEFS+=	USE_INET6
CFLAGS+=	${CPPFLAGS}

.include "../../mk/bsd.prefs.mk"

FETCHMAIL_USE_SSL?=YES

.if defined(FETCHMAIL_USE_SSL) && ${FETCHMAIL_USE_SSL} == YES
USE_SSL=	yes
CONFIGURE_ARGS+=--with-ssl=${SSLBASE}
.else
CONFIGURE_ARGS+=--without-ssl
.else
.endif

BUILD_DEFS+=	FETCHMAIL_USE_SSL

.if defined(KERBEROS)
USE_KERBEROS=	yes
CONFIGURE_ARGS+=--with-kerberos=yes
.if ${MACHINE_PLATFORM:MNetBSD-1.[0-4]*-i386} == ""
REPLACE_KERBEROS_LIBS=	# defined
.endif
.else
CONFIGURE_ARGS+=--with-kerberos=no
.endif

.if defined(USE_INET6) && ${USE_INET6} == YES
CONFIGURE_ARGS+=--enable-inet6
.endif

FDOC=	${PREFIX}/share/doc/fetchmail

post-extract:
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
	(cd ${WRKSRC}; autoreconf)

post-build:
	tbl ${WRKSRC}/fetchmail.tbl >${WRKSRC}/fetchmail.man

post-install:
	${INSTALL_DATA_DIR} ${FDOC}
	cd ${WRKSRC} && ${INSTALL_DATA} \
	   FAQ NOTES FEATURES README COPYING \
	   fetchmail-FAQ.html fetchmail-features.html \
	   design-notes.html ${FDOC}

.include "../../mk/bsd.pkg.mk"
