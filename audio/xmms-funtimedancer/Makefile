# $NetBSD: Makefile,v 1.11 2005/02/21 20:26:09 hubertf Exp $
#

DISTNAME=	FunTimeDancer-0.1
PKGNAME=	xmms-funtimedancer-0.1
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ftd/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} FunTimeDancer-packs-1.0.tar.gz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/ftd/
COMMENT=	XMMS plugin displaying an animation

USE_X11=	yes
USE_BUILDLINK3=	yes

post-install:
	cd ${WRKDIR} && \
		${PAX} -rw -pe FunTimeDancer ${PREFIX}/lib/xmms/Visualization

.include "../../audio/xmms/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
