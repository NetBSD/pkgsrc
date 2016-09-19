# $NetBSD: Makefile,v 1.2 2016/09/19 18:21:52 jakllsch Exp $

DISTNAME=	dtc-1.4.2
CATEGORIES=	sysutils devel
MASTER_SITES=	ftp://ftp.kernel.org/pub/software/utils/dtc/

MAINTAINER=	joe.davis512@gmail.com
HOMEPAGE=	http://devicetree.org/
COMMENT=	Device Tree Compiler (dtc)
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake bison

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}

.include "../../mk/bsd.pkg.mk"
