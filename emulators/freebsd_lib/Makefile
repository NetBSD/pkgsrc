# $NetBSD: Makefile,v 1.32 2023/12/30 17:52:24 zafer Exp $
#

DISTNAME=		freebsd_lib-2.2.7
PKGREVISION=		9
CATEGORIES=		emulators
MASTER_SITES=		#

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Libraries necessary for FreeBSD compatibility, including XFree86

ONLY_FOR_PLATFORM=	NetBSD-*-i386

WRKSRC=			${WRKDIR}
NO_BUILD=		yes

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/emul/freebsd
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/emul/freebsd/var/run
	(cd ${WRKSRC} && ${FIND} usr -type d -print) | \
		(cd ${DESTDIR}${PREFIX}/emul/freebsd && \
			${XARGS} ${INSTALL_DATA_DIR})
	cd ${WRKSRC} && for file in `${FIND} usr -name '*.*' -print`; do \
		${INSTALL_DATA} $$file \
			${DESTDIR}${PREFIX}/emul/freebsd/$$file; \
	done
	${TOUCH} ${DESTDIR}${PREFIX}/emul/freebsd/var/run/ld.so.hints

.include "../../mk/bsd.pkg.mk"
