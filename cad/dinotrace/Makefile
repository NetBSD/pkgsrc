# $NetBSD: Makefile,v 1.43 2012/10/03 21:53:59 wiz Exp $
#

DISTNAME=	dinotrace-9.3c
PKGREVISION=	2
CATEGORIES=	cad
MASTER_SITES=	http://www.veripool.com/ftp/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.veripool.com/dinotrace/
COMMENT=	Tool for viewing the output of digital simulators

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
INFO_FILES=		YES
USE_TOOLS+=		gmake perl

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
