# $NetBSD: Makefile,v 1.1.1.1 2003/02/14 23:56:38 hubertf Exp $
#

DISTNAME=	FunTimeDancer-0.1
PKGNAME=	xmms-${DISTNAME:S/FunTimeDancer/funtimedancer/}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=/ftd/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} FunTimeDancer-packs-1.0.tar.gz

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://sourceforge.net/projects/ftd/
COMMENT=	XMMS plugin displaying an animation

USE_X11=	yes
USE_BUILDLINK2=	yes

post-install:
		cd ${WRKSRC}/../FunTimeDancer ; \
		${PAX} -rw -pe . ${PREFIX}/lib/xmms/Visualization/FunTimeDancer

.include "../../audio/xmms/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
