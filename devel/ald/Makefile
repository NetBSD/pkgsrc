# $NetBSD: Makefile,v 1.3 2003/06/02 01:20:59 jschauma Exp $
#

DISTNAME=	ald-0.0.19d
PKGNAME=	ald-0.0.19
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	devel
MASTER_SITES=	http://ellipse.mcs.drexel.edu/source/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://ellipse.mcs.drexel.edu/ald.html
COMMENT=	Very nice x86 assembly-level debugger ported to NetBSD

ONLY_FOR_PLATFORM=	NetBSD-1.5*-i386 NetBSD-1.6*-i386

GNU_CONFIGURE=	YES

#do-build:
#	cd ${WRKSRC} && ${MAKE_PROGRAM} -f ${MAKEFILE} ${ALL_TARGET}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/ald ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/ald.8 ${PREFIX}/man/man8
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ald
	cd ${WRKSRC} && ${INSTALL_DATA} INSTALL README ChangeLog \
		${PREFIX}/share/doc/ald

.include "../../mk/bsd.pkg.mk"
