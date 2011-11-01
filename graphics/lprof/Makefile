# $NetBSD: Makefile,v 1.20 2011/11/01 06:01:41 sbd Exp $
#

DISTNAME=		lprof-1.10.1
PKGREVISION=		13
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=lprof/}

MAINTAINER=		gdt@NetBSD.org
HOMEPAGE=		http://lprof.sourceforge.net/
COMMENT=		ICC Profile generation tool (for IT8.7 targets)

MAKE_JOBS_SAFE=		no

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake

MAKE_ENV+=	BASEDIR=${PREFIX:Q}
MAKE_ENV+=	LDFLAGS=${LDFLAGS:M*:Q}

# mis-usage of ${DESTDIR}
DESTDIR_VARNAME=	#empty
INSTALL_MAKE_FLAGS+=	BASEDIR=${DESTDIR}${PREFIX}

PTHREAD_AUTO_VARS=	yes

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
