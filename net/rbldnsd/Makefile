# $NetBSD: Makefile,v 1.1.1.1 2006/12/08 22:14:12 cube Exp $
#

DISTNAME=	rbldnsd_0.996a
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	net
MASTER_SITES=	http://www.corpit.ru/mjt/rbldnsd/

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://www.corpit.ru/mjt/rbldnsd/
COMMENT=	Efficient DNS daemon to serve DNSBL zones

WRKSRC=		${WRKDIR}/rbldnsd-0.996a
HAS_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	RBLDNSD_USER RBLDNSD_GROUP RBLDNSD_DIR VARBASE

RBLDNSD_USER?=	rbldns
RBLDNSD_GROUP?=	rbldns
RBLDNSD_DIR?=	${VARBASE}/chroot/rbldnsd

PKG_GROUPS=	${RBLDNSD_GROUP}
PKG_USERS=	${RBLDNSD_USER}:${RBLDNSD_GROUP}
PKG_HOME.${RBLDNSD_USER}=	${RBLDNSD_DIR}

FILES_SUBST+=	RBLDNSD_USER=${RBLDNSD_USER} RBLDNSD_GROUP=${RBLDNSD_GROUP}
RCD_SCRIPTS=	rbldnsd

.include "options.mk"

RBLDNSD_DOCS=	NEWS README.user

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rbldnsd ${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/rbldnsd.8 ${PREFIX}/${PKGMANDIR}/man8/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/rbldnsd
	set -e; for doc in ${RBLDNSD_DOCS}; do \
	    ${INSTALL_DATA} ${WRKSRC}/"$$doc" ${PREFIX}/share/doc/rbldnsd/; \
	    done

.include "../../mk/bsd.pkg.mk"
