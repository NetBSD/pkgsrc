# $NetBSD: Makefile,v 1.6 1999/08/18 09:28:02 agc Exp $

DISTNAME=	cyrus-imapd-v1.5.14
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/

MAINTAINER=	kim@tac.nyc.ny.us

DEPENDS+=	tcl-8.0.5:../../lang/tcl80

GNU_CONFIGURE=	yes

# XXX This package is not ready for general use!
# XXX I've imported it because my work on it has
# XXX been stalled for a while, and someone might
# XXX benefit from what is here already.
# XXX
# XXX Eventually I will clean this up.
# XXX
# XXX + Kim

CONFIGURE_ARGS+=	--with-cyrus-prefix=${LOCALBASE}/cyrus
CONFIGURE_ARGS+=	--with-statedir=/var/run
CONFIGURE_ARGS+=	--includedir=${LOCALBASE}/include/tcl8.0
CONFIGURE_ARGS+=	--enable-netscapehack

BUILD_DEFS+=		USE_KERBEROS4

.include "../../mk/bsd.prefs.mk"

.if defined(USE_KERBEROS4)
CONFIGURE_ARGS+=	--with-login=krb
RESTRICTED=		uses Kerberos encryption code
.endif

.include "../../mk/bsd.pkg.mk"

PKGNAME!=	${ECHO} "${DISTNAME}" | ${SED} -e 's/-imapd-v/-/'
