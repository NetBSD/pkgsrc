# $NetBSD: Makefile,v 1.2 2000/03/25 21:09:16 dmcmahill Exp $
#

DISTNAME=	verilog-20000318
PKGNAME=	verilog-current-20000318
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
