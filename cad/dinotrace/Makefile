# $NetBSD: Makefile,v 1.27 2004/01/28 12:21:54 xtraeme Exp $
#

DISTNAME=	dinotrace-9.1k
PKGREVISION=	1
CATEGORIES=	cad
MASTER_SITES=	http://www.veripool.com/ftp/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE= 	http://www.veripool.com/dinotrace/
COMMENT=	Tool for viewing the output of digital simulators

USE_BUILDLINK2=		YES
USE_X11=		YES
GNU_CONFIGURE=		YES
USE_PERL5=		build
INFO_FILES=		dinotrace.info

.include "../../mk/motif.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
