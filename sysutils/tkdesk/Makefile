# $NetBSD: Makefile,v 1.2 2002/10/25 09:21:11 wiz Exp $
#

DISTNAME=	tkdesk-1.2
CATEGORIES=	sysutils
MASTER_SITES=	http://tkdesk.sourceforge.net/dist/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://tkdesk.sourceforge.net/
COMMENT=	graphical file manager

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-tcl=${BUILDLINK_PREFIX.tcl}/lib	\
		--with-tk=${BUILDLINK_PREFIX.tk}/lib	\
		--with-itcl=${BUILDLINK_PREFIX.tcl-itcl}/lib	\
		--with-blt=${BUILDLINK_PREFIX.blt}/lib

pre-install:
	${RM} -Rf ${WRKSRC}/tcldesk/configs/.trash
	${FIND} ${WRKSRC}/tcldesk -type f -name '*.orig' | ${XARGS} ${RM} -rf
	${FIND} ${WRKSRC}/tcldesk -name '*' -exec ${TOUCH} {} ';'

.include "../../lang/tcl/buildlink2.mk"
.include "../../lang/tcl-itcl/buildlink2.mk"
.include "../../x11/blt/buildlink2.mk"
.include "../../x11/tk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
