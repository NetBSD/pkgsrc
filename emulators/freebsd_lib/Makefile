# $NetBSD: Makefile,v 1.22 2006/06/19 23:19:24 jlam Exp $
#

DISTNAME=		freebsd_lib-2.2.7
PKGREVISION=		2
CATEGORIES=		emulators
MASTER_SITES=		http://www.flame.org/NetBSD/

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Libraries necessary for FreeBSD compatibility, including XFree86

ONLY_FOR_PLATFORM=	NetBSD-*-i386

WRKSRC=			${WRKDIR}
NO_BUILD=		yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/emul/freebsd
	${INSTALL_DATA_DIR} ${PREFIX}/emul/freebsd/var/run
	(cd ${WRKSRC} && ${FIND} usr -type d -print) | \
		(cd ${PREFIX}/emul/freebsd && ${XARGS} ${INSTALL_DATA_DIR})
	cd ${WRKSRC} && for file in `${FIND} usr -name '*.*' -print`; do \
		${INSTALL_DATA} $$file ${PREFIX}/emul/freebsd/$$file; \
	done
	${TOUCH} ${PREFIX}/emul/freebsd/var/run/ld.so.hints

.include "../../mk/bsd.pkg.mk"
