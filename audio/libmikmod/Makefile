# $NetBSD: Makefile,v 1.5 2000/04/02 16:07:04 pooka Exp $

DISTNAME=	libmikmod-3.1.9
CATEGORIES=	audio
MASTER_SITES=	http://mikmod.darkorb.net/libmikmod/

MAINTAINER=	kuebart@mathematik.uni-ulm.de
HOMEPAGE=	http://mikmod.darkorb.net/

DEPENDS+=	esound-0.2.*:../../audio/esound

USE_LIBTOOL=	YES
USE_GMAKE=	YES
USE_GTEXINFO=	YES
GNU_CONFIGURE=	YES

pre-build:
	${RM} -f ${WRKSRC}/docs/mikmod.info*

.include "../../mk/bsd.pkg.mk"
