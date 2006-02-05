# $NetBSD: Makefile,v 1.16 2006/02/05 23:08:18 joerg Exp $
#

DISTNAME=	FunTimeDancer-0.1
PKGNAME=	xmms-funtimedancer-0.1
PKGREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ftd/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} FunTimeDancer-packs-1.0.tar.gz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/ftd/
COMMENT=	XMMS plugin displaying an animation

post-install:
	cd ${WRKDIR} && \
		${PAX} -rw -pe FunTimeDancer ${PREFIX}/lib/xmms/Visualization

.include "../../audio/xmms/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
