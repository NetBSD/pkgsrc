# $NetBSD: Makefile,v 1.11 1998/07/04 09:37:29 mycroft Exp $
#

DISTNAME=       fetchmail-4.5.1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.ccil.org/pub/esr/fetchmail/

MAINTAINER=	mycroft@netbsd.org

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
