# $NetBSD: Makefile,v 1.1.1.1 2002/07/03 09:27:00 dmcmahill Exp $
# FreeBSD Id: ports/x11-fm/tkdesk/Makefile,v 1.18 2001/09/03 18:17:47 knu Exp

DISTNAME=	tkdesk-1.2
CATEGORIES=	sysutils
MASTER_SITES=	http://tkdesk.sourceforge.net/dist/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://tkdesk.sourceforge.net/
COMMENT=	graphical file manager

DEPENDS+=	tcl-itcl>=3.2:../../lang/tcl-itcl
DEPENDS+=	blt>=2.4:../../x11/blt

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-tcl=${LOCALBASE}/lib	\
		--with-tk=${LOCALBASE}/lib	\
		--with-itcl=${LOCALBASE}/lib	\
		--with-blt=${LOCALBASE}/lib

pre-install:
	${RM} -Rf ${WRKSRC}/tcldesk/configs/.trash
	${FIND} ${WRKSRC}/tcldesk -type f -name '*.orig' | ${XARGS} ${RM} -rf
	${FIND} ${WRKSRC}/tcldesk -name '*' -exec ${TOUCH} {} ';'

.include "../../lang/tcl/buildlink.mk"
.include "../../x11/tk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
