# $NetBSD: Makefile,v 1.26 2001/02/06 12:41:37 tron Exp $
# FreeBSD Id: Makefile,v 1.10 1997/07/17 15:12:41 max Exp 
#

DISTNAME=      	slang-1.4.3
PKGNAME=       	lib${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=  	ftp://space.mit.edu/pub/davis/slang/v1.4/ \
		http://gd.tuwien.ac.at/editors/davis/slang/v1.4/ \
		ftp://ftp.uni-stuttgart.de/pub/mirror/space.mit.edu/pub/davis/slang/v1.4/

MAINTAINER=    	packages@netbsd.org
HOMEPAGE=	http://www.s-lang.org/

GNU_CONFIGURE= 	yes
USE_LIBTOOL=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/slang
	${MV} ${PREFIX}/share/doc/slang/slangdoc.html \
		${PREFIX}/share/doc/html/slang

.include "../../mk/bsd.pkg.mk"
