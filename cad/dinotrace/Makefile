# $NetBSD: Makefile,v 1.29 2004/10/03 00:13:12 tv Exp $
#

DISTNAME=	dinotrace-9.1k
PKGREVISION=	2
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

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
