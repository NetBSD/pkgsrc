# $NetBSD: Makefile,v 1.140 2004/03/31 02:22:04 jlam Exp $

DISTNAME=	fetchmail-6.2.5
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://catb.org/~esr/fetchmail/ \
		http://sunsite.unc.edu/pub/Linux/system/mail/pop/

MAINTAINER=	frueauf@NetBSD.org
HOMEPAGE=	http://catb.org/~esr/fetchmail/
COMMENT=	Batch mail retrieval/forwarding utility for pop2, pop3, apop, imap

PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-hesiod

BUILD_DEFS+=		USE_INET6
LDFLAGS+=		${CFLAGS}

.include "../../mk/bsd.prefs.mk"

FETCHMAIL_USE_SSL?=	YES
BUILD_DEFS+=		FETCHMAIL_USE_SSL

.if defined(FETCHMAIL_USE_SSL) && !empty(FETCHMAIL_USE_SSL:M[yY][eE][sS])
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE}
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

.if defined(KERBEROS)
PKG_USE_KERBEROS=	yes
CONFIGURE_ARGS+=	--with-kerberos=yes
.  if ${MACHINE_PLATFORM:MNetBSD-1.[0-4]*-i386} == ""
REPLACE_KERBEROS_LIBS=	# defined
.  endif
.else
CONFIGURE_ARGS+=	--with-kerberos=no
.endif

.if defined(USE_INET6) && !empty(USE_INET6:M[yY][eE][sS])
CONFIGURE_ARGS+=	--enable-inet6
.endif

FDOC=		${PREFIX}/share/doc/fetchmail
RCD_SCRIPTS=	fetchmail

post-extract:
	@${RM} -f ${WRKSRC}/intl/libintl.h
.if ${OPSYS} == "NetBSD"
	@${RM} -f ${WRKSRC}/md5.h
.endif

.if defined(REPLACE_KERBEROS_LIBS)
post-configure:
	cd ${WRKSRC} && \
	for F in configure.in configure; do \
		${SED} -e "s/-lkrb -ldes/-lkrb -ldes -lcom_err -lroken/" \
			$$F > $$F.mod; \
		${MV} -f $$F.mod $$F; \
	done
	${CHMOD} a+x ${WRKSRC}/configure
.endif

post-build:
	for file in ${WRKSRC}/fetchmail.man; do				\
		${MV} -f $$file $$file.tbl;				\
		tbl $$file.tbl > $$file;				\
	done

post-install:
	${INSTALL_DATA_DIR} ${FDOC}
	cd ${WRKSRC} && ${INSTALL_DATA} \
	   FAQ NOTES FEATURES README COPYING \
	   fetchmail-FAQ.html fetchmail-features.html \
	   design-notes.html ${FDOC}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
