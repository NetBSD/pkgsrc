# $NetBSD: Makefile,v 1.3 1999/03/07 00:41:51 kim Exp $

DISTNAME=	cyrus-imapd-v1.5.14
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/

MAINTAINER=	kim@tac.nyc.ny.us

GNU_CONFIGURE=	yes

# XXX This package is not ready for general use!
# XXX I've imported it because my work on it has
# XXX been stalled for a while, and someone might
# XXX benefit from what is here already.
# XXX
# XXX Eventually I will clean this up.
# XXX
# XXX + Kim

CONFIGURE_ARGS+=	--with-cyrus-prefix=${PREFIX}/cyrus
CONFIGURE_ARGS+=	--with-statedir=/var/run
CONFIGURE_ARGS+=	--with-tcl=/usr/local/tcl

.include "../../mk/bsd.pkg.mk"

PKGNAME!=	${ECHO} "${DISTNAME}" | ${SED} -e 's/-imapd-v/-/'

.if exists(/usr/lib/libkrb.a) && \
    (defined(MAKE_EBONES) || defined(MAKE_KERBEROS4))
CONFIGURE_ARGS+=	--with-login=krb
.endif
