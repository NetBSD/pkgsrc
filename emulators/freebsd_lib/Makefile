# $NetBSD: Makefile,v 1.10 2001/05/19 03:56:35 jlam Exp $
#

DISTNAME=		freebsd_lib-2.2.7
CATEGORIES=		emulators
MASTER_SITES=		http://www.flame.org/NetBSD/

MAINTAINER=		packages@netbsd.org
COMMENT=		libraries necessary for FreeBSD compatibility, including XFree86

ONLY_FOR_PLATFORM=	NetBSD-*-i386

NO_BUILD=		yes
NO_WRKSUBDIR=		yes

do-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/emul/freebsd
	@(cd ${WRKSRC} && ${FIND} usr -type d -print) | \
		(cd ${PREFIX}/emul/freebsd && ${XARGS} ${INSTALL_DATA_DIR})
	@cd ${WRKSRC} && for file in `${FIND} usr -name '*.*' -print`; do \
		${INSTALL_DATA} $$file ${PREFIX}/emul/freebsd/$$file; \
	done
	@${SETENV} PKG_PREFIX="${PREFIX}" ${SH} ${INSTALL_FILE} - POST-INSTALL

show-shlib-type:
	@${ECHO} a.out

.include "../../mk/bsd.pkg.mk"
