# $NetBSD: Makefile,v 1.2 1999/12/17 11:12:22 agc Exp $

DISTNAME=	libmikmod-3.1.7
CATEGORIES=	audio
# The files at multimania.com seem to be corrupted
MASTER_SITES=	http://mikmod.darkorb.net/libmikmod/ \
		http://www.multimania.com/miodrag/mikmod/libmikmod/

MAINTAINER=	kuebart@mathematik.uni-ulm.de
HOMEPAGE=	http://www.multimania.com/miodrag/mikmod/

DEPENDS+=	esound-0.2.15:../../audio/esound

USE_LIBTOOL=
USE_GMAKE=
GNU_CONFIGURE=

pre-build:
	${RM} -f ${WRKSRC}/docs/mikmod.info*

.include "../../mk/bsd.pkg.mk"
