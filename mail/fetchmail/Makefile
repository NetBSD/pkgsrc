# $NetBSD: Makefile,v 1.46 1999/07/07 23:28:12 itojun Exp $
#

DISTNAME=       fetchmail-5.0.5
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

.if defined(USE_KERBEROS4)
CONFIGURE_ARGS+=--with-kerberos=yes
RESTRICTED=	uses Kerberos encryption code
.endif
.if defined(USE_INET6)
CONFIGURE_ARGS+=--enable-inet6
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
