# $NetBSD: Makefile,v 1.22 2008/01/18 05:08:47 tnn Exp $

DISTNAME=		openntpd-3.9p1
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		ftp://ftp.openbsd.org/pub/OpenBSD/OpenNTPD/ \
			ftp://ftp5.usa.openbsd.org/pub/OpenBSD/OpenNTPD/ \
			ftp://ftp.de.openbsd.org/pub/unix/OpenBSD/OpenNTPD/ \
			http://ftp.lug.udel.edu/pub/OpenBSD/OpenNTPD/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.openntpd.org/
COMMENT=		Free implementation of the Network Time Protocol

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CONFLICTS+=		ntp-[0-9]*

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	sysconfdir=${PKG_SYSCONFDIR:Q}

EGDIR=			${PREFIX}/share/examples/openntpd
CONF_FILES=		${EGDIR}/ntpd.conf ${PKG_SYSCONFDIR}/ntpd.conf

RCD_SCRIPTS=		openntpd
PKG_GROUPS=		_ntp
PKG_USERS=		_ntp:_ntp
PKG_HOME._ntp=		${VARBASE}/chroot/ntpd

OWN_DIRS=		${VARBASE}/chroot/ntpd
INSTALLATION_DIRS=	${PKGMANDIR}/man5 ${PKGMANDIR}/man8 sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ntpd ${PREFIX}/sbin/ntpd
	${INSTALL_MAN} ${WRKSRC}/ntpd.8 ${PREFIX}/${PKGMANDIR}/man8/ntpd.8
	${INSTALL_MAN} ${WRKSRC}/ntpd.conf.5 ${PREFIX}/${PKGMANDIR}/man5/ntpd.conf.5

post-install:
	@${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/ntpd.conf ${EGDIR}/ntpd.conf

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
