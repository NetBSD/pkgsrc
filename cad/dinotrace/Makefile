# $NetBSD: Makefile,v 1.18 2002/09/21 01:24:43 jlam Exp $
#

DISTNAME=	dinotrace-9.1g
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

.include "../../mk/motif.buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
