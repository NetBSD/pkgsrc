# $NetBSD: Makefile,v 1.22 2003/07/15 09:48:35 drochner Exp $
#

DISTNAME=	dinotrace-9.1k
CATEGORIES=	cad
MASTER_SITES=	http://www.veripool.com/ftp/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE= 	http://www.veripool.com/dinotrace/
COMMENT=	tool for viewing the output of digital simulators

INFO_FILES=	dinotrace.info

USE_BUILDLINK2=		YES
USE_X11BASE=		YES
GNU_CONFIGURE=		YES
USE_PERL5=		build
USE_NEW_TEXINFO=	YES
INFO_FILES=		dinotrace.info

.include "../../mk/motif.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
