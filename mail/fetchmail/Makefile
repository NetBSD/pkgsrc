# $NetBSD: Makefile,v 1.40 1999/04/11 09:00:42 frueauf Exp $
#

DISTNAME=       fetchmail-5.0.0
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.ccil.org/pub/esr/fetchmail/ \
		http://www.tuxedo.org/~esr/fetchmail/ \
		http://sunsite.unc.edu/pub/Linux/system/mail/pop/

MAINTAINER=	mycroft@netbsd.org
HOMEPAGE=	http://sagan.earthspace.net/~esr/fetchmail/

BUILD_DEPENDS+=	autoconf:../../devel/autoconf

GNU_CONFIGURE=	yes
CONFIGURE_ENV=  LDFLAGS="${CFLAGS}"

.include "../../mk/bsd.prefs.mk"

.if exists(/usr/lib/libkrb.a) && (defined(MAKE_EBONES) || defined(MAKE_KERBEROS4))
CONFIGURE_ARGS += --with-kerberos=yes
.endif

FDOC=	${PREFIX}/share/doc/fetchmail

post-extract:
	${RM} -f ${WRKSRC}/md5.h

pre-configure:
	(cd ${WRKSRC}; autoreconf)

post-install:
	${INSTALL} -d -m 555 -o ${DOCOWN} -g ${DOCGRP} ${FDOC}
	cd ${WRKSRC} && ${INSTALL_DATA} \
	   sample.rcfile FAQ NOTES FEATURES README COPYING \
	   fetchmail-FAQ.html fetchmail-features.html \
	   design-notes.html ${FDOC}

.include "../../mk/bsd.pkg.mk"
