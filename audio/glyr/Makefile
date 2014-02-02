# $NetBSD: Makefile,v 1.1 2014/02/02 23:35:03 rodent Exp $
#

DISTNAME=	1.0.3
PKGNAME=	glyr-${DISTNAME}
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
