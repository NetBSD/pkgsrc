# $NetBSD: Makefile,v 1.54 2018/11/12 03:52:13 ryoon Exp $
#

DISTNAME=	libmng-1.0.10
PKGNAME=	${DISTNAME:S/libmng/gmngview/}
PKGREVISION=	30
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libmng/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=
COMMENT=	Simple GTK-based MNG viewer

WRKSRC=		${WRKDIR}/${DISTNAME}/contrib/gcc/gtk-mng-view
MAKE_ENV+=	LIBMNG_PREFIX=${BUILDLINK_PREFIX.mng}

EXTRACT_ELEMENTS=	*/contrib/gcc/gtk-mng*
EXTRACT_USING=		bsdtar
INSTALLATION_DIRS=	bin
USE_TOOLS+=		pkg-config

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gmngview ${DESTDIR}${PREFIX}/bin

.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
