# $NetBSD: Makefile,v 1.2 1998/04/15 10:38:30 agc Exp $
#

DISTNAME=	tclX8.0.2
PKGNAME=	tclX-8.0.2
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.neosoft.com/pub/tcl/tclx-distrib/

MAINTAINER=	tron@netbsd.org

LIB_DEPENDS=	tk80.1:${PORTSDIR}/x11/tk80

WRKSRC=		${WRKDIR}/tclX8.0.2/unix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-shared --with-tk
CONFIGURE_ENV+=	PREFIX=${PREFIX} TCL_SHLIB_LD_LIBS=-L${PREFIX}/lib

MAN3=	TclCommandWriting.3 Tcl_HandleAlloc.3 Tcl_HandleFree.3 \
	Tcl_HandleTblInit.3 Tcl_HandleTblRelease.3 Tcl_HandleTblUseCount.3 \
	Tcl_HandleWalk.3 Tcl_HandleXlate.3 TclX_NewKeyedListObj.3 \
	TclX_KeyedListGet.3 TclX_KeyedListSet.3 TclX_KeyedListDelete.3 \
	TclX_KeyedListGetKeys.3 Tclx_Init.3 Tclxcmd_Init.3 TclX_Main.3 \
	Tkx_Init.3 TkX_Main.3
MANN=	ckalloc.n memory.n ckfree.n Tcl_DisplayMemory.n Tcl_InitMemory.n \
	Tcl_ValidateAllMemory.n TclX.n

.include "../../mk/bsd.pkg.mk"
