# $NetBSD: Makefile,v 1.5 2004/04/24 22:40:40 wiz Exp $
#

DISTNAME=		OpenPBS_2_3_16
PKGNAME=		openpbs-2.3.16
CATEGORIES=		parallel sysutils
MASTER_SITES=		http://www.openpbs.org/UserArea/Download/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.openpbs.org/
COMMENT=		Generic network queueing system

INTERACTIVE_STAGE=	fetch

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX}
USE_X11=		yes
USE_BUILDLINK3=		yes

REPLACE_INTERPRETER+=	tcl
_REPLACE.tcl.old=	.*/bin/pbs_tclsh
_REPLACE.tcl.new=	${PREFIX}/bin/tclsh
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

.include "../../x11/tk83/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
