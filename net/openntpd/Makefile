# $NetBSD: Makefile,v 1.12 2005/06/28 17:13:25 peter Exp $

DISTNAME=		openntpd-3.7p1
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.openbsd.org/pub/OpenBSD/OpenNTPD/ \
			ftp://ftp5.usa.openbsd.org/pub/OpenBSD/OpenNTPD/ \
			ftp://ftp.de.openbsd.org/pub/unix/OpenBSD/OpenNTPD/ \
			http://ftp.lug.udel.edu/pub/OpenBSD/OpenNTPD/

MAINTAINER=		peter@pointless.nl
HOMEPAGE=		http://www.openntpd.org/
COMMENT=                Free implementation of the Network Time Protocol

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CONFLICTS+=		ntp-[0-9]*

USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	sysconfdir=${PKG_SYSCONFDIR}

EGDIR=			${PREFIX}/share/examples/openntpd
CONF_FILES=		${EGDIR}/ntpd.conf ${PKG_SYSCONFDIR}/ntpd.conf

RCD_SCRIPTS=		openntpd
PKG_USERS=		_ntp:_ntp::ntpd\\ pseudo-user:${VARBASE}/chroot/ntpd:/sbin/nologin
PKG_GROUPS=		_ntp

OWN_DIRS=		${VARBASE}/chroot/ntpd
INSTALLATION_DIRS=	man/man5 man/man8 sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ntpd ${PREFIX}/sbin/ntpd
	${INSTALL_MAN} ${WRKSRC}/ntpd.8 ${PREFIX}/man/man8/ntpd.8
	${INSTALL_MAN} ${WRKSRC}/ntpd.conf.5 ${PREFIX}/man/man5/ntpd.conf.5

post-install:
	@${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/ntpd.conf ${EGDIR}/ntpd.conf

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
