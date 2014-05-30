# $NetBSD: Makefile,v 1.7 2014/05/30 21:06:39 pettai Exp $
#

DISTNAME=	rbldnsd-0.997a
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	net
MASTER_SITES=	http://www.corpit.ru/mjt/rbldnsd/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.corpit.ru/mjt/rbldnsd/
COMMENT=	Efficient DNS daemon to serve DNSBL zones

WRKSRC=		${WRKDIR}/rbldnsd-0.997a
HAS_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	RBLDNSD_DIR VARBASE

RBLDNSD_USER?=	rbldns
RBLDNSD_GROUP?=	rbldns
RBLDNSD_DIR?=	${VARBASE}/chroot/rbldnsd

PKG_GROUPS=	${RBLDNSD_GROUP}
PKG_USERS=	${RBLDNSD_USER}:${RBLDNSD_GROUP}
PKG_HOME.${RBLDNSD_USER}=	${RBLDNSD_DIR}

PKG_GROUPS_VARS=	RBLDNSD_GROUP
PKG_USERS_VARS=		RBLDNSD_USER

FILES_SUBST+=	RBLDNSD_USER=${RBLDNSD_USER} RBLDNSD_GROUP=${RBLDNSD_GROUP}
RCD_SCRIPTS=	rbldnsd

.include "options.mk"

RBLDNSD_DOCS=	NEWS README.user

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin share/doc/rbldnsd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rbldnsd ${DESTDIR}${PREFIX}/sbin/
	${INSTALL_MAN} ${WRKSRC}/rbldnsd.8 \
	    ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/
	set -e; for doc in ${RBLDNSD_DOCS}; do \
	    ${INSTALL_DATA} ${WRKSRC}/"$$doc" \
	    ${DESTDIR}/${PREFIX}/share/doc/rbldnsd/; \
	    done

.include "../../mk/bsd.pkg.mk"
