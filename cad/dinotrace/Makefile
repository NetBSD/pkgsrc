# $NetBSD: Makefile,v 1.26 2003/08/09 10:32:13 seb Exp $
#

DISTNAME=	dinotrace-9.1k
CATEGORIES=	cad
MASTER_SITES=	http://www.veripool.com/ftp/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE= 	http://www.veripool.com/dinotrace/
COMMENT=	Tool for viewing the output of digital simulators

USE_BUILDLINK2=		YES
USE_X11BASE=		YES
GNU_CONFIGURE=		YES
USE_PERL5=		build
INFO_FILES=		dinotrace.info

.include "../../mk/motif.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
