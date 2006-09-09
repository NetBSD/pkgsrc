# $NetBSD: Makefile,v 1.11 2006/09/09 02:41:56 obache Exp $
#

DISTNAME=	ald-0.0.19d
PKGNAME=	ald-0.0.19
CATEGORIES=	devel
MASTER_SITES=	http://ellipse.mcs.drexel.edu/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ellipse.mcs.drexel.edu/ald.html
COMMENT=	Very nice x86 assembly-level debugger ported to NetBSD

ONLY_FOR_PLATFORM=	NetBSD-1.5*-i386 NetBSD-1.6*-i386 NetBSD-[2-9]*-i386

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
GNU_CONFIGURE=	YES

INSTALLATION_DIRS=	bin man/man8

#do-build:
#	cd ${WRKSRC} && ${MAKE_PROGRAM} -f ${MAKE_FILE} ${BUILD_TARGET}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/ald ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/ald.8 ${PREFIX}/man/man8
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ald
	cd ${WRKSRC} && ${INSTALL_DATA} INSTALL README ChangeLog \
		${PREFIX}/share/doc/ald

.include "../../mk/bsd.pkg.mk"
