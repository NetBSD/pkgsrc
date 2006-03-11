# $NetBSD: Makefile,v 1.11 2006/03/11 10:07:50 ghen Exp $
#

DISTNAME=		OpenPBS_2_3_16
PKGNAME=		openpbs-2.3.16
PKGREVISION=		1
CATEGORIES=		parallel sysutils
MASTER_SITES=		http://www.openpbs.org/UserArea/Download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.openpbs.org/
COMMENT=		Generic network queueing system

INTERACTIVE_STAGE=	fetch

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}

REPLACE_INTERPRETER+=	tcl
REPLACE.tcl.old=	.*/bin/pbs_tclsh
REPLACE.tcl.new=	${PREFIX}/bin/tclsh
REPLACE_FILES.tcl+=	src/gui/buildindex.src
REPLACE_FILES.tcl+=	src/tools/xpbsmon/buildindex.src

REPLACE_INTERPRETER+=	tk
REPLACE.tk.old=	.*/bin/wish
REPLACE.tk.new=	${PREFIX}/bin/wish
REPLACE_FILES.tk+=	src/gui/xpbs.src

REPLACE_INTERPRETER+=	tk2
REPLACE.tk2.old=	.*/bin/pbs_wish
REPLACE.tk2.new=	${PREFIX}/bin/pbs_wish
REPLACE_FILES.tk2+=	src/tools/xpbsmon/xpbsmon.src

_CONFIGURE_POSTREQ+=     replace-interpreter

.include "../../x11/tk83/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
