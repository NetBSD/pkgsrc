# $NetBSD: Makefile,v 1.5 2000/05/11 01:33:49 dmcmahill Exp $
#

DISTNAME=	verilog-20000506
PKGNAME=	verilog-current-20000506
CATEGORIES=	cad
MASTER_SITES=	ftp://icarus.com/pub/eda/verilog/snapshots/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://icarus.com/eda/verilog/index.html

BUILD_DEPENDS+=	bison:../../devel/bison
BUILD_DEPENDS+=	gperf:../../devel/gperf

CONFLICTS+=	verilog

GNU_CONFIGURE=	yes
USE_GMAKE=      yes

.include "../../mk/bsd.pkg.mk"
