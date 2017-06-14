# $NetBSD: Makefile,v 1.4 2017/06/14 06:29:36 maya Exp $

DISTNAME=	dtc-1.4.2
PKGREVISION=	1
CATEGORIES=	sysutils devel
MASTER_SITES=	ftp://ftp.kernel.org/pub/software/utils/dtc/

MAINTAINER=	joe.davis512@gmail.com
HOMEPAGE=	http://devicetree.org/
COMMENT=	Device Tree Compiler (dtc)
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake bison flex bash:run

REPLACE_BASH+=	dtdiff

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}

.include "../../mk/bsd.pkg.mk"
