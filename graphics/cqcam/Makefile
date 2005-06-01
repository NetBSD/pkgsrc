# $NetBSD: Makefile,v 1.24 2005/06/01 18:02:54 jlam Exp $
#

DISTNAME=		cqcam-0.45a
PKGREVISION=		2
CATEGORIES=    		graphics x11
MASTER_SITES=		http://www.cs.duke.edu/~reynolds/cqcam/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.cs.duke.edu/~reynolds/cqcam/
COMMENT=		Free Color QuickCam control program

ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-alpha

LICENSE=		no-profit

HAS_CONFIGURE=		YES
USE_LANGUAGES=		c c++

CONFIGURE_ENV+=		CAT=${CAT:Q} ECHO=${ECHO:Q}			\
			TCLCONFIG_SH=${TCLCONFIG_SH:Q}

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"

post-patch:
	${CHMOD} a+x ${WRKSRC}/configure
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.in

post-install:
	${RM} ${PREFIX}/man/man1/webcam.1.gz
	${RM} ${PREFIX}/man/man1/xcqcam.1.gz
	${LN} ${PREFIX}/man/man1/cqcam.1 ${PREFIX}/man/man1/webcam.1
	${LN} ${PREFIX}/man/man1/cqcam.1 ${PREFIX}/man/man1/xcqcam.1

.include "../../mk/bsd.pkg.mk"
