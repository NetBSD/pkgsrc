# $NetBSD: Makefile,v 1.10 2001/09/12 02:27:55 jlam Exp $
#

DISTNAME=	dinotrace-9.1d
CATEGORIES=	cad
MASTER_SITES=	http://www.veripool.com/ftp/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE= 	http://www.veripool.com/dinotrace/
COMMENT=	tool for viewing the output of digital simulators

INFO_FILES=	dinotrace.info

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES

.include "../../mk/motif.buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
