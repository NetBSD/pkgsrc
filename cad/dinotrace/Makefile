# $NetBSD: Makefile,v 1.46 2013/06/01 14:05:13 shattered Exp $
#

DISTNAME=	dinotrace-9.4c
CATEGORIES=	cad
MASTER_SITES=	http://www.veripool.org/ftp/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.veripool.org/dinotrace/
COMMENT=	Tool for viewing the output of digital simulators

LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		YES
INFO_FILES=		YES
USE_TOOLS+=		gmake perl

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
