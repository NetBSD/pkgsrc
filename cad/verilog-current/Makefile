# $NetBSD: Makefile,v 1.1.1.1 2000/03/07 16:09:15 dmcmahill Exp $
#

DISTNAME=	verilog-20000219
PKGNAME=	verilog-current-20000219
CATEGORIES=	cad
MASTER_SITES=	ftp://icarus.com/pub/eda/verilog/snapshots/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://icarus.com/eda/verilog/index.html

BUILD_DEPENDS+=	bison:../../devel/bison

CONFLICTS+=	verilog

GNU_CONFIGURE=	YES
USE_GMAKE=      yes

.include "../../mk/bsd.pkg.mk"
