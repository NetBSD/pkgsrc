# $NetBSD: Makefile,v 1.1.1.1 2003/08/13 05:23:00 mrg Exp $

DISTNAME=       atitvout-0.4
WRKSRC=		${WRKDIR}/atitvout
CATEGORIES=	sysutils graphics
MASTER_SITES=	http://www.stud.uni-hamburg.de/users/lennart/projects/atitvout/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.stud.uni-hamburg.de/users/lennart/projects/atitvout/
COMMENT=	Allows TV-Out connector support under Linux/NetBSD

ONLY_FOR_PLATFORM=	NetBSD-*-i386 # Linux-*-i386 [gnumakefile needs work]

USE_CONFIGURE=		YES

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
DEPENDS+=	lrmi>=0.8:../../emulators/lrmi

MAKEFILE=	Makefile.bsd

do-configure:
	${CP} ${FILESDIR}/Makefile.bsd ${WRKSRC}
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/atitvout ${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/atitvout
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/atitvout
	${INSTALL_DATA} ${WRKSRC}/test.sh ${PREFIX}/share/doc/atitvout

.include "../../mk/bsd.pkg.mk"
