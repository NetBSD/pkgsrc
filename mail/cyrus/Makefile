# $NetBSD: Makefile,v 1.11 2000/03/16 13:03:48 wiz Exp $

DISTNAME=		cyrus-imapd-v1.5.14
PKGNAME=		cyrus-1.5.14
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/

MAINTAINER=		kim@tac.nyc.ny.us
HOMEPAGE=		http://asg.web.cmu.edu/cyrus/imapd/

DEPENDS+=		tcl-8.0.5:../../lang/tcl80

GNU_CONFIGURE=		yes

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
CONFIGURE_ARGS+=	--includedir=${LOCALBASE}/include/tcl8.0
CONFIGURE_ARGS+=	--enable-netscapehack

.include "../../mk/bsd.prefs.mk"

.if defined(KERBEROS) && ${KERBEROS} == 4
USE_KERBEROS=		yes
CONFIGURE_ARGS+=	--with-login=krb
.endif

# Deliver must be executable by all on machines with local
# users sending to cyrus mailboxes.

post-install:
	@${CHMOD} a+rx ${PREFIX}/cyrus/bin/deliver

.include "../../mk/bsd.pkg.mk"
