# $NetBSD: Makefile,v 1.25 2003/08/08 15:42:15 seb Exp $
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
USE_NEW_TEXINFO=	YES
INFO_FILES=		dinotrace.info

.include "../../mk/motif.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
