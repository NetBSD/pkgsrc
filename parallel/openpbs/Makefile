# $NetBSD: Makefile,v 1.1.1.1 2003/07/17 14:19:16 agc Exp $
#

DISTNAME=		OpenPBS_2_3_16
PKGNAME=		openpbs-2.3.16
CATEGORIES=		parallel sysutils
MASTER_SITES=		http://www.openpbs.org/UserArea/Download/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.openpbs.org/
COMMENT=		Generic network queueing system

INTERACTIVE_STAGE=	fetch

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
USE_X11=		yes
USE_BUILDLINK2=		yes

REPLACE_INTERPRETER+=	tcl
_REPLACE.tcl.old=	.*/bin/pbs_tclsh
_REPLACE.tcl.new=	${PREFIX}/bin/pbs_tclsh
_REPLACE_FILES.tcl+=	src/gui/buildindex.src
_REPLACE_FILES.tcl+=	src/tools/xpbsmon/buildindex.src

REPLACE_INTERPRETER+=	tk
_REPLACE.tk.old=	.*/bin/wish
_REPLACE.tk.new=	${PREFIX}/bin/wish
_REPLACE_FILES.tk+=	src/gui/xpbs.src

REPLACE_INTERPRETER+=	tk2
_REPLACE.tk2.old=	.*/bin/pbs_wish
_REPLACE.tk2.new=	${PREFIX}/bin/pbs_wish
_REPLACE_FILES.tk2+=	src/tools/xpbsmon/xpbsmon.src

_CONFIGURE_POSTREQ+=     replace-interpreter

.include "../../x11/tk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
