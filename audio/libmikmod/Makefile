# $NetBSD: Makefile,v 1.4 2000/03/07 22:42:00 tron Exp $

DISTNAME=	libmikmod-3.1.7
CATEGORIES=	audio
# The files at multimania.com seem to be corrupted
MASTER_SITES=	http://mikmod.darkorb.net/libmikmod/ \
		http://www.multimania.com/miodrag/mikmod/libmikmod/

MAINTAINER=	kuebart@mathematik.uni-ulm.de
HOMEPAGE=	http://www.multimania.com/miodrag/mikmod/

DEPENDS+=	esound-0.2.*:../../audio/esound

USE_LIBTOOL=	YES
USE_GMAKE=	YES
USE_GTEXINFO=	YES
GNU_CONFIGURE=	YES

pre-build:
	${RM} -f ${WRKSRC}/docs/mikmod.info*

.include "../../mk/bsd.pkg.mk"
