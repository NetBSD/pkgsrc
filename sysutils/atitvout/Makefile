# $NetBSD: Makefile,v 1.6 2005/06/17 03:50:33 jlam Exp $

DISTNAME=       atitvout-0.4
PKGREVISION=	1
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
.include "../../emulators/lrmi/buildlink3.mk"

MAKEFILE=	Makefile.bsd

do-configure:
	${CP} ${FILESDIR}/Makefile.bsd ${WRKSRC}
.endif

SUBST_CLASSES+=	sh
SUBST_STAGE.sh=	post-patch
SUBST_FILES.sh=	test.sh
SUBST_SED.sh=	-e "s,@PREFIX@,${PREFIX},"
SUBST_MESSAGE.sh=	"Fixing stupid bash scripts."

INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/atitvout ${PREFIX}/sbin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/atitvout
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/atitvout
	${INSTALL_DATA} ${WRKSRC}/test.sh ${PREFIX}/share/doc/atitvout

.include "../../mk/bsd.pkg.mk"
