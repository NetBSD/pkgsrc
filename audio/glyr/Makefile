# $NetBSD: Makefile,v 1.4 2014/04/09 07:27:02 obache Exp $
#

DISTNAME=	1.0.5
PKGNAME=	glyr-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://github.com/sahib/glyr/archive/
DIST_SUBDIR=	${PKGBASE}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/sahib/glyr/
COMMENT=	Music related metadata search engine with CLI and C API
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=	pkg-config
USE_CMAKE=	yes

PKGCONFIG_OVERRIDE+=	glyr/libglyr.pc.in

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.10
.include "../../devel/glib2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
