# $NetBSD: Makefile,v 1.3 2004/01/20 12:26:15 agc Exp $

DISTNAME=       atitvout-0.4
CATEGORIES=	sysutils graphics
MASTER_SITES=	http://www.stud.uni-hamburg.de/users/lennart/projects/atitvout/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.stud.uni-hamburg.de/users/lennart/projects/atitvout/
COMMENT=	Allows TV-Out connector support under Linux/NetBSD

ONLY_FOR_PLATFORM=	NetBSD-*-i386 # Linux-*-i386 [gnumakefile needs work]

WRKSRC=			${WRKDIR}/atitvout
USE_CONFIGURE=		YES

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
DEPENDS+=	lrmi>=0.8nb1:../../emulators/lrmi

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
