# $NetBSD: Makefile,v 1.9 2000/11/24 18:03:58 dmcmahill Exp $
#

DISTNAME=	verilog-20001119
PKGNAME=	verilog-current-20001119
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
