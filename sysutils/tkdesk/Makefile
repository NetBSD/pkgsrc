# $NetBSD: Makefile,v 1.8 2004/03/08 20:27:16 minskim Exp $
#

DISTNAME=	tkdesk-1.2
CATEGORIES=	sysutils
MASTER_SITES=	http://tkdesk.sourceforge.net/dist/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://tkdesk.sourceforge.net/
COMMENT=	Graphical file manager

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-tcl=${BUILDLINK_PREFIX.tcl}/lib	\
		--with-tk=${BUILDLINK_PREFIX.tk}/lib	\
		--with-itcl=${BUILDLINK_PREFIX.tcl-itcl}/lib	\
		--with-blt=${BUILDLINK_PREFIX.blt}/lib

pre-install:
	${RM} -Rf ${WRKSRC}/tcldesk/configs/.trash
	${FIND} ${WRKSRC}/tcldesk -type f -name '*.orig' -print | ${XARGS} ${RM} -rf
	${FIND} ${WRKSRC}/tcldesk -name '*' -exec ${TOUCH} {} ';'

.include "../../lang/tcl83/buildlink2.mk"
.include "../../lang/tcl-itcl/buildlink2.mk"
.include "../../x11/blt/buildlink2.mk"
.include "../../x11/tk83/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
