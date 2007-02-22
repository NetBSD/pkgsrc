# $NetBSD: Makefile,v 1.19 2007/02/22 19:01:15 wiz Exp $
#

DISTNAME=	FunTimeDancer-0.1
PKGNAME=	xmms-funtimedancer-0.1
PKGREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ftd/}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} FunTimeDancer-packs-1.0.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/ftd/
COMMENT=	XMMS plugin displaying an animation

post-install:
	cd ${WRKDIR} && \
		pax -rw -pp FunTimeDancer ${PREFIX}/lib/xmms/Visualization

.include "../../audio/xmms/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
