# $NetBSD: Makefile,v 1.1.1.1 2000/07/30 20:08:52 tron Exp $

DISTNAME=	wmnet-1.06
CATEGORIES=	net x11
MASTER_SITES=	http://www.digitalkaos.net/linux/wmnet/download/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.digitalkaos.net/linux/wmnet/

USE_IMAKE=	YES

do-patch:
	cd ${WRKSRC}; for i in *; do ${GREP} -q OpenBSD $$i && ${SED} s/OpenBSD/NetBSD/g $$i > temp && ${MV} temp $$i; done

.include "../../mk/bsd.pkg.mk"
