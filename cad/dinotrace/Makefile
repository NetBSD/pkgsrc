# $NetBSD: Makefile,v 1.32 2005/05/22 20:07:40 jlam Exp $
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
USE_TOOLS+=		gmake

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
