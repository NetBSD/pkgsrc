# $NetBSD: Makefile,v 1.25 2020/04/16 14:03:29 manu Exp $
#

DISTNAME=	squirrelmail-imap_proxy-1.2.7
PKGNAME=	imapproxy-1.2.7
PKGREVISION=	6
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=squirrelmail/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.imapproxy.org/
COMMENT=	Simple connection caching IMAP proxy daemon

GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--exec_prefix=${DESTDIR}${PREFIX}
BUILD_DEFS+=		VARBASE
CFLAGS+=		-DDEFAULT_CONFIG_FILE=\"${PREFIX}/etc/imapproxy.conf\"
CFLAGS+=		-DDEFAULT_PID_FILE=\"${VARBASE}/run/imapproxy.pid\"
RCD_SCRIPTS=		imapproxy

IMAPPROXY_USER?=	imapproxy
IMAPPROXY_GROUP?=	imapproxy
IMAPPROXY_CHROOT?=	${VARBASE}/chroot/imapproxy
IMAPPROXY_DOC?=		share/doc/imapproxy
IMAPPROXY_EXAMPLES?=	share/examples/imapproxy

PKG_GROUPS_VARS+=		IMAPPROXY_GROUP
PKG_USERS_VARS+=		IMAPPROXY_USER
PKG_GROUPS=			${IMAPPROXY_GROUP}
PKG_USERS=			${IMAPPROXY_USER}:${IMAPPROXY_GROUP}
PKG_GECOS.${IMAPPROXY_USER}=	IMAP Proxy pseudo-user
PKG_HOME.${IMAPPROXY_USER}=	${IMAPPROXY_CHROOT}

INSTALLATION_DIRS+=	sbin
INSTALLATION_DIRS+=	${IMAPPROXY_DOC}
INSTALLATION_DIRS+=	${IMAPPROXY_EXAMPLES}

MAKE_DIRS=		${VARBASE}/chroot
OWN_DIRS=		${VARBASE}/chroot/imapproxy

post-install:
.for doc in COPYING ChangeLog README README.known_issues README.ssl
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DESTDIR}${PREFIX}/${IMAPPROXY_DOC}
.endfor
	${INSTALL_DATA} ${WRKSRC}/scripts/imapproxy.conf \
			${DESTDIR}${PREFIX}/${IMAPPROXY_EXAMPLES}

.include "../../mk/curses.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
