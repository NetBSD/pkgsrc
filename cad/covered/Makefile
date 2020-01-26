# $NetBSD: Makefile,v 1.29 2020/01/26 05:26:15 rillig Exp $
#

DISTNAME=	covered-0.7.10
PKGREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=covered/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://covered.sourceforge.net/
COMMENT=	Verilog code coverage analyzer (stable release version)
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	YES
USE_TOOLS+=	bison gmake lex

# This is required for TCL/TK dependency
CPPFLAGS+=	-DUSE_INTERP_RESULT

.include "../../cad/iverilog/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
