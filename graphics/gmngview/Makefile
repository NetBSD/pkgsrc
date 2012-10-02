# $NetBSD: Makefile,v 1.33 2012/10/02 17:11:11 tron Exp $
#

DISTNAME=	libmng-1.0.10
PKGNAME=	${DISTNAME:S/libmng/gmngview/}
PKGREVISION=	13
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libmng/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=
COMMENT=	Simple GTK-based MNG viewer

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${DISTNAME}/contrib/gcc/gtk-mng-view
MAKE_ENV+=	LIBMNG_PREFIX=${BUILDLINK_PREFIX.mng:Q}

EXTRACT_ELEMENTS=	*/contrib/gcc/gtk-mng*
INSTALLATION_DIRS=	bin
USE_TOOLS+=		pkg-config

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gmngview ${DESTDIR}${PREFIX}/bin

.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
