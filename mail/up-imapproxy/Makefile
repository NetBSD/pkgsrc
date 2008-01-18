# $NetBSD: Makefile,v 1.3 2008/01/18 05:08:31 tnn Exp $

DISTNAME=	up-imapproxy-1.2.5
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.imapproxy.org/downloads/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.imapproxy.org/
COMMENT=	Connection caching IMAP proxy server

GNU_CONFIGURE=	YES
RCD_SCRIPTS=	upimapproxy

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	include/imapproxy.h
SUBST_SED.paths=	-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"
SUBST_MESSAGE.paths=	Fixing hard coded paths.

CONF_FILES=	${PREFIX}/share/examples/up-imapproxy/imapproxy.conf \
			${PKG_SYSCONFDIR}/imapproxy.conf

INSTALLATION_DIRS+= sbin share/doc/up-imapproxy share/examples/up-imapproxy

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/up-imapproxy
	${INSTALL_DATA} ${WRKSRC}/README.ssl ${PREFIX}/share/doc/up-imapproxy
	${INSTALL_DATA} ${WRKSRC}/README.known_issues \
		 ${PREFIX}/share/doc/up-imapproxy
	${INSTALL_DATA} ${WRKSRC}/scripts/imapproxy.conf \
		 ${PREFIX}/share/examples/up-imapproxy

.include "../../mk/bsd.pkg.mk"
