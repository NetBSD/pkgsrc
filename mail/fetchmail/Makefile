# $NetBSD: Makefile,v 1.66 2000/03/12 12:26:29 fredb Exp $
#

DISTNAME=       fetchmail-5.3.2
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.ccil.org/pub/esr/fetchmail/ \
		http://www.tuxedo.org/~esr/fetchmail/ \
		http://sunsite.unc.edu/pub/Linux/system/mail/pop/

MAINTAINER=	mycroft@netbsd.org
HOMEPAGE=	http://www.tuxedo.org/~esr/fetchmail/

BUILD_DEPENDS+=	${LOCALBASE}/bin/autoconf:../../devel/autoconf

GNU_CONFIGURE=	yes
CONFIGURE_ENV=  LDFLAGS="${CFLAGS}" YACC="${YACC}"

BUILD_DEFS+=	USE_INET6

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=--without-hesiod
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
