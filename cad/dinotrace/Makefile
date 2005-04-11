# $NetBSD: Makefile,v 1.31 2005/04/11 21:45:01 tv Exp $
#

DISTNAME=	dinotrace-9.2a
CATEGORIES=	cad
MASTER_SITES=	http://www.veripool.com/ftp/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE= 	http://www.veripool.com/dinotrace/
COMMENT=	Tool for viewing the output of digital simulators

GNU_CONFIGURE=		YES
INFO_FILES=		dinotrace.info
USE_PERL5=		build
USE_X11=		YES
USE_GNU_TOOLS+=		make

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
