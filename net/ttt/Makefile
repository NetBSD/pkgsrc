# $NetBSD: Makefile,v 1.1.1.1 2000/05/22 03:55:16 sakamoto Exp $
#

DISTNAME=	ttt-1.4
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.csl.sony.co.jp/pub/kjc/

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://www.csl.sony.co.jp/person/kjc/software.html

DEPENDS+=	blt-2.*:../../x11/blt

USE_X11=	YES

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	ttt_cv_tcl_lib="${LOCALBASE}/lib/tcl8.0"
CONFIGURE_ENV+=	TCL_PREFIX="${LOCALBASE}" TCL_MAJOR_VERSION=8 TCL_MINOR_VERSION=0
CONFIGURE_ENV+=	TK_PREFIX="${LOCALBASE}" TK_MAJOR_VERSION=8 TK_MINOR_VERSION=0

.include "../../mk/bsd.pkg.mk"
