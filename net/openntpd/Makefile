# $NetBSD: Makefile,v 1.4 2004/10/03 00:17:57 tv Exp $

DISTNAME=		openntpd-20040719p
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES=		http://www.openntpd.org/dist/portable/

MAINTAINER=		peter@pointless.nl
HOMEPAGE=		http://www.openntpd.org/
COMMENT=                Free implementation of the Network Time Protocol

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CONFLICTS+=		ntp-[0-9]*

USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes

EGDIR=			${PREFIX}/share/examples/openntpd
CONF_FILES=		${EGDIR}/ntpd.conf ${PKG_SYSCONFDIR}/ntpd.conf

RCD_SCRIPTS=		openntpd
PKG_USERS=		_ntp:nogroup::ntpd\\ pseudo-user:${VARBASE}/chroot/ntpd:/sbin/nologin

OWN_DIRS=		${VARBASE}/chroot/ntpd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ntpd ${PREFIX}/sbin/ntpd
	${INSTALL_MAN} ${WRKSRC}/ntpd.8 ${PREFIX}/man/man8/ntpd.8
	${INSTALL_MAN} ${WRKSRC}/ntpd.conf.5 ${PREFIX}/man/man5/ntpd.conf.5

post-install:
	@${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/ntpd.conf ${EGDIR}/ntpd.conf

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
