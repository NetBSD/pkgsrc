# $NetBSD: Makefile,v 1.145 2004/07/30 21:05:41 jlam Exp $

DISTNAME=	fetchmail-6.2.5
PKGREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://catb.org/~esr/fetchmail/ \
		http://sunsite.unc.edu/pub/Linux/system/mail/pop/

MAINTAINER=	frueauf@NetBSD.org
HOMEPAGE=	http://catb.org/~esr/fetchmail/
COMMENT=	Batch mail retrieval/forwarding utility for pop2, pop3, apop, imap

PKG_INSTALLATION_TYPES=	overwrite pkgviews

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-hesiod
USE_TBL=		yes

BUILD_DEFS+=		USE_INET6
LDFLAGS+=		${CFLAGS}

.include "../../mk/bsd.prefs.mk"

# Global and legacy options
.if defined(KERBEROS) && defined(USE_INET6) || defined(FETCHMAIL_USE_SSL)
.  if !defined(PKG_OPTIONS.fetchmail)
.    if defined(KERBEROS)
PKG_OPTIONS.fetchmail+=	kerberos4
.    endif
.    if defined(USE_INET6) && !empty(USE_INET6:M[yY][eE][sS])
PKG_OPTIONS.fetchmail+=	inet6
.    endif
.    if defined(FETCHMAIL_USE_SSL) && !empty(FETCHMAIL_USE_SSL:M[yY][eE][sS])
PKG_OPTIONS.fetchmail+=	ssl
.    endif
.  endif
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.fetchmail
PKG_SUPPORTED_OPTIONS=	inet6 kerberos4 ssl
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-inet6
.endif

.if !empty(PKG_OPTIONS:Mkerberos4)
CRYPTO+=		uses Kerberos encryption code
CONFIGURE_ARGS+=	--with-kerberos=yes
.  if empty(MACHINE_PLATFORM:MNetBSD-1.[0-4]*-i386)
REPLACE_KERBEROS_LIBS=	# defined
.  endif
.else
CONFIGURE_ARGS+=	--with-kerberos=no
.endif

.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE}
.else
CONFIGURE_ARGS+=	--without-ssl
.endif

DOCDIR=		${PREFIX}/share/doc/fetchmail
RCD_SCRIPTS=	fetchmail

.include "../../devel/gettext-lib/buildlink3.mk"

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
		${TBL} $$file.tbl > $$file;				\
	done

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}; for file in					\
		FAQ NOTES FEATURES README COPYING			\
		fetchmail-FAQ.html fetchmail-features.html		\
		design-notes.html;					\
	do								\
		${INSTALL_DATA} $$file ${DOCDIR};			\
	done

.include "../../mk/bsd.pkg.mk"
