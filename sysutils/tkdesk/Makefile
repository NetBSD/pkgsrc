# $NetBSD: Makefile,v 1.16 2006/11/10 17:44:34 tv Exp $
#

DISTNAME=	tkdesk-2.0
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://tkdesk.sourceforge.net/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tkdesk.sourceforge.net/
COMMENT=	Graphical file manager

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-tcl=${BUILDLINK_PREFIX.tcl}/lib	\
		--with-tk=${BUILDLINK_PREFIX.tk}/lib	\
		--with-itcl=${BUILDLINK_PREFIX.tcl-itcl}/lib	\
		--with-blt=${BUILDLINK_PREFIX.blt}/lib
MAKE_ENV+=	LIB_RUNTIME_DIR=${BUILDLINK_PREFIX.tcl-itcl:Q}/lib \
		PAX=${PAX:Q}

.include "../../lang/tcl/buildlink3.mk"
.include "../../lang/tcl-itcl/buildlink3.mk"
.include "../../x11/blt/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"

pre-install:
	${RM} -Rf ${WRKSRC}/tcldesk/configs/.trash
	${FIND} ${WRKSRC}/tcldesk -type f -name '*.orig' -print | ${XARGS} ${RM} -rf
	${FIND} ${WRKSRC}/tcldesk -type f -print | ${XARGS} ${TOUCH}

.include "../../mk/bsd.pkg.mk"
