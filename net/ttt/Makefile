# $NetBSD: Makefile,v 1.5 2001/02/17 18:19:48 wiz Exp $
#

DISTNAME=	ttt-1.6
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.csl.sony.co.jp/pub/kjc/

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://www.csl.sony.co.jp/person/kjc/software.html
COMMENT=	Tele Traffic Tapper

DEPENDS+=	blt-2.*:../../x11/blt

USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	ttt_cv_tcl_lib="${LOCALBASE}/lib/tcl8.0"
CONFIGURE_ENV+=	TCL_PREFIX="${LOCALBASE}" TCL_MAJOR_VERSION=8 TCL_MINOR_VERSION=0
CONFIGURE_ENV+=	TK_PREFIX="${LOCALBASE}" TK_MAJOR_VERSION=8 TK_MINOR_VERSION=0
INSTALL_TARGET=	install install-man

.include "../../mk/bsd.pkg.mk"
