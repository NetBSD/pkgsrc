# $NetBSD: Makefile,v 1.72 2000/05/21 19:19:34 kim Exp $
#

DISTNAME=       fetchmail-5.3.8
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.ccil.org/pub/esr/fetchmail/ \
		http://www.tuxedo.org/~esr/fetchmail/ \
		http://sunsite.unc.edu/pub/Linux/system/mail/pop/

MAINTAINER=	mycroft@netbsd.org
HOMEPAGE=	http://www.tuxedo.org/~esr/fetchmail/

BUILD_DEPENDS+=	${LOCALBASE}/bin/autoconf:../../devel/autoconf

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--without-hesiod
CONFIGURE_ENV+=  LDFLAGS="${CFLAGS}"

BUILD_DEFS+=	USE_INET6
RESTRICTED=	"Crypto; export-controlled"

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

.if defined(KERBEROS) && ${KERBEROS} == 4
USE_KERBEROS=	yes
CONFIGURE_ARGS+=--with-kerberos=yes
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

pre-configure:
	(cd ${WRKSRC}; autoreconf)

post-build:
	tbl ${WRKSRC}/fetchmail.tbl >${WRKSRC}/fetchmail.man

post-install:
	${INSTALL} -d -m 555 -o ${DOCOWN} -g ${DOCGRP} ${FDOC}
	cd ${WRKSRC} && ${INSTALL_DATA} \
	   sample.rcfile FAQ NOTES FEATURES README COPYING \
	   fetchmail-FAQ.html fetchmail-features.html \
	   design-notes.html ${FDOC}

.include "../../mk/bsd.pkg.mk"
