# $NetBSD: Makefile,v 1.30 1998/12/20 10:37:07 frueauf Exp $
#

DISTNAME=       fetchmail-4.7.1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.ccil.org/pub/esr/fetchmail/ \
		http://www.tuxedo.org/~esr/fetchmail/ \
		http://sunsite.unc.edu/pub/Linux/system/mail/pop/

MAINTAINER=	mycroft@netbsd.org
HOMEPAGE=	http://sagan.earthspace.net/~esr/fetchmail/

CONFLICTS=	fetchmail-4.3.6 fetchmail-4.3.9 fetchmail-4.5.1 \
		fetchmail-4.5.2 fetchmail-4.5.3 fetchmail-4.5.4 \
		fetchmail-4.5.5 fetchmail-4.5.6 fetchmail-4.5.7 \
		fetchmail-4.6.0 fetchmail-4.6.1 fetchmail-4.6.2 \
		fetchmail-4.6.3 fetchmail-4.6.4 fetchmail-4.6.5 \
		fetchmail-4.6.6 fetchmail-4.6.7 fetchmail-4.6.9 \
		fetchmail-4.7.0

GNU_CONFIGURE=	yes
CONFIGURE_ENV=  LDFLAGS="${CFLAGS}"

.include "../../mk/bsd.prefs.mk"

.if exists(/usr/lib/libkrb.a) && (defined(MAKE_EBONES) || defined(MAKE_KERBEROS4))
CONFIGURE_ARGS += --with-kerberos=yes
.endif

FDOC=   ${PREFIX}/share/doc/fetchmail

post-extract:
	${RM} -f ${WRKSRC}/md5.h

post-install:
	${INSTALL} -d -m 555 -o ${DOCOWN} -g ${DOCGRP} ${FDOC}
	cd ${WRKSRC} && ${INSTALL_DATA} \
	   sample.rcfile FAQ NOTES FEATURES README COPYING \
	   fetchmail-FAQ.html fetchmail-features.html \
	   design-notes.html ${FDOC}

.include "../../mk/bsd.pkg.mk"
