# $NetBSD: Makefile,v 1.17 2003/07/21 16:45:55 martti Exp $
#

DISTNAME=		freebsd_lib-2.2.7
PKGREVISION=		1
WRKSRC=			${WRKDIR}
CATEGORIES=		emulators
MASTER_SITES=		http://www.flame.org/NetBSD/

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Libraries necessary for FreeBSD compatibility, including XFree86

ONLY_FOR_PLATFORM=	NetBSD-*-i386

NO_BUILD=		yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/emul/freebsd
	${INSTALL_DATA_DIR} ${PREFIX}/emul/freebsd/var/run
	(cd ${WRKSRC} && ${FIND} usr -type d -print) | \
		(cd ${PREFIX}/emul/freebsd && ${XARGS} ${INSTALL_DATA_DIR})
	cd ${WRKSRC} && for file in `${FIND} usr -name '*.*' -print`; do \
		${INSTALL_DATA} $$file ${PREFIX}/emul/freebsd/$$file; \
	done
	@${SETENV} PKG_PREFIX="${PREFIX}" ${SH} ${INSTALL_FILE} - POST-INSTALL
	${TOUCH} ${PREFIX}/emul/freebsd/var/run/ld.so.hints

show-shlib-type:
	@${ECHO} a.out

.include "../../mk/bsd.pkg.mk"
