# $NetBSD: Makefile,v 1.7 1999/12/29 01:41:00 wiz Exp $
#

DISTNAME=		freebsd_lib-2.2.7
CATEGORIES=		emulators
MASTER_SITES=		http://www.flame.org/NetBSD/

MAINTAINER=		packages@netbsd.org

ONLY_FOR_PLATFORM=	NetBSD-*-i386

#
# The distfile is distributed under the GPL, so no re-distribution of
# binaries without source.
#
# Source can be found on
#	http://www.flame.org/NetBSD/freebsd_lib.2.2.7-src.tar.gz.
# It seems nasty to have to provide source when FreeBSD already does.
#
MIRROR_DISTFILE=	no

NO_BUILD=		yes
NO_WRKSUBDIR=		yes

do-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/emul/freebsd
	@(cd ${WRKSRC} && ${FIND} usr -type d -print) | \
		(cd ${PREFIX}/emul/freebsd && xargs ${INSTALL_DATA_DIR})
	@cd ${WRKSRC} && for file in `${FIND} usr -name '*.*' -print`; do \
		${INSTALL_DATA} $$file ${PREFIX}/emul/freebsd/$$file; \
	done
	@${SETENV} PKG_PREFIX="${PREFIX}" ${SH} ${INSTALL_FILE} - POST-INSTALL

show-shlib-type:
	@${ECHO} a.out

.include "../../mk/bsd.pkg.mk"
