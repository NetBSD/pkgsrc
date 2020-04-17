# $NetBSD: Makefile,v 1.1 2020/04/17 11:28:02 tm Exp $

VERSION=	1.2.8
PKGNAME=	up-imapproxy-${VERSION}
DISTNAME=	up-imapproxy_${VERSION}~svn20171105.orig
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/u/up-imapproxy/}
EXTRACT_SUFX=	.tar.bz2
CONFLICTS+=	imapproxy-[0-9]*

MAINTAINER=	tm@NetBSD.org
HOMEPAGE=	http://www.imapproxy.org/
COMMENT=	Connection caching IMAP proxy server
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	YES

WRKSRC=		${WRKDIR}/squirrelmail.imap_proxy

RCD_SCRIPTS=			imapproxy
RCD_SCRIPT_SRC.imapproxy=	${WRKSRC}/scripts/imapproxy-bsd.init

INSTALLATION_DIRS+=	sbin share/doc/imapproxy share/examples/imapproxy
CONF_FILES=		${PREFIX}/share/examples/imapproxy/imapproxy.conf \
				${PKG_SYSCONFDIR}/imapproxy.conf

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	include/imapproxy.h
SUBST_VARS.paths=	PKG_SYSCONFDIR VARBASE
SUBST_MESSAGE.paths=	Fixing hard coded paths.

post-install:
.for doc in COPYING ChangeLog README README.known_issues README.ssl
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DESTDIR}${PREFIX}/share/doc/imapproxy
.endfor
	${INSTALL_DATA} ${WRKSRC}/scripts/imapproxy.conf \
		 ${DESTDIR}${PREFIX}/share/examples/imapproxy

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
