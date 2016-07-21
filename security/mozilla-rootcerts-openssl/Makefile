# $NetBSD: Makefile,v 1.5 2016/07/21 12:38:05 wiz Exp $

PKGNAME=	mozilla-rootcerts-openssl-2
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

BUILD_DEPENDS+=	mozilla-rootcerts-1.0.20160610{,nb[0-9]*}:../../security/mozilla-rootcerts
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
# Update: even for pkgsrc openssl it's in /etc for SSLDIR, as per the
# mozilla-rootcerts script.
#
.if !empty(USE_BUILTIN.openssl:M[yY][eE][sS])
PLACE=			/etc
SET_PREFIX=		yes
PLIST_SUBST+=		MYETCDIR=etc
CHECK_FILES_SUPPORTED=	no
.else
PLACE=			${MY_PKG_SYSCONFDIR}
SET_PREFIX=		yes
PLIST_SUBST+=		MYETCDIR=${MY_PKG_SYSCONFDIR:S/^${PREFIX}//}
.endif

NOT_FOR_UNPRIVILEGED=	yes

OPENSSLDIR=		${PLACE}/openssl/certs
SSLDIR=			/etc/ssl/certs

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${OPENSSLDIR}
	#${INSTALL_DATA_DIR} ${DESTDIR}${SSLDIR} # must *not* exist
	cd ${WRKSRC} && ${SCRIPT} -d ${DESTDIR} install
	${CHMOD} go+r ${DESTDIR}${OPENSSLDIR}/*.pem
	${CHMOD} go+r ${DESTDIR}${SSLDIR}/*.crt

.include "../../mk/bsd.pkg.mk"

# This must be after bsd.pkg.mk is included to work.
MY_PKG_SYSCONFDIR:=	${PKG_SYSCONFDIR}
.if ${SET_PREFIX} == "yes"
PREFIX=			/
.endif
