# $NetBSD: Makefile,v 1.13 2020/05/30 12:56:54 tnn Exp $

PKGNAME=	mozilla-rootcerts-openssl-2.4
CATEGORIES=	security
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	dholland@NetBSD.org
#HOMEPAGE=	none
COMMENT=	Wedge for installing and managing mozilla-rootcerts
LICENSE=	modified-bsd

USE_TOOLS+=	openssl
WRKSRC=		${WRKDIR}
BUILD_DIRS=	# empty

BUILD_DEPENDS+=	mozilla-rootcerts-1.0.20200529{,nb[0-9]*}:../../security/mozilla-rootcerts
SCRIPT=		${LOCALBASE}/sbin/mozilla-rootcerts

CHECK_BUILTIN.openssl=	yes
.include "../../security/openssl/builtin.mk"
CHECK_BUILTIN.openssl=	no

#
# This package needs to install directly into openssl's certs directory
# because openssl is dumb and doesn't support multiple cert directories.
# (Otherwise we'd install under ${PREFIX}/share.)
#
# For native openssl this is in /etc outside of ${PREFIX}. Beware.
#
.if !empty(USE_BUILTIN.openssl:M[yY][eE][sS])
NOT_FOR_UNPRIVILEGED=	yes
PLACE=			/etc
SET_PREFIX=		yes
PLIST_SUBST+=		MYETCDIR=etc
CHECK_FILES_SUPPORTED=	no
.else
PLACE=			${MY_PKG_SYSCONFDIR}
# probably SET_PREFIX should not be set
SET_PREFIX=		yes
PLIST_SUBST+=		MYETCDIR=${MY_PKG_SYSCONFDIR:S/^${PREFIX}//}
.endif

OPENSSLDIR=		${PLACE}/openssl/certs

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${OPENSSLDIR}
	cd ${WRKSRC} && ${SCRIPT} -d ${DESTDIR} install
	${CHMOD} go+r ${DESTDIR}${OPENSSLDIR}/*.pem
	${CHMOD} go+r ${DESTDIR}${OPENSSLDIR}/*.crt

.include "../../mk/bsd.pkg.mk"

# This must be after bsd.pkg.mk is included to work.
MY_PKG_SYSCONFDIR:=	${PKG_SYSCONFDIR}
.if ${SET_PREFIX} == "yes"
PREFIX=			/
.endif
