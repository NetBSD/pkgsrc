# $NetBSD: Makefile,v 1.4 2000/06/22 03:15:31 dmcmahill Exp $
#

DISTNAME=       verilog-0.3
CATEGORIES=     cad
MASTER_SITES=   ftp://icarus.com/pub/eda/verilog/v0.3/

MAINTAINER=     dmcmahill@netbsd.org
HOMEPAGE=       http://icarus.com/eda/verilog/index.html

BUILD_DEPENDS+= bison:../../devel/bison
BUILD_DEPENDS+=	gperf:../../devel/gperf

CONFLICTS+=     verilog-current

GNU_CONFIGURE=	yes
USE_GMAKE=      yes

.include "../../mk/bsd.pkg.mk"
