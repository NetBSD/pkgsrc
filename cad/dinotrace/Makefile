# $NetBSD: Makefile,v 1.30 2005/02/23 11:07:35 dmcmahill Exp $
#

DISTNAME=	dinotrace-9.2a
CATEGORIES=	cad
MASTER_SITES=	http://www.veripool.com/ftp/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE= 	http://www.veripool.com/dinotrace/
COMMENT=	Tool for viewing the output of digital simulators

GNU_CONFIGURE=		YES
INFO_FILES=		dinotrace.info
USE_BUILDLINK3=		YES
USE_PERL5=		build
USE_X11=		YES
USE_GNU_TOOLS+=		make

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
