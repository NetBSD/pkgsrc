# $NetBSD: Makefile,v 1.10 2003/03/07 11:40:58 wiz Exp $
#

DISTNAME=	tuxpaint-0.9.10
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tuxpaint/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.newbreedsoftware.com/tuxpaint/
COMMENT=	drawing program for small children

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
USE_PKGLOCALEDIR=	YES
USE_GMAKE=		YES
MANCOMPRESSED=		YES

MAKE_ENV+=		CONFDIR="${PKG_SYSCONFDIR}"
EGDIR=			${PREFIX}/share/examples/tuxpaint
CONF_FILES=		${EGDIR}/tuxpaint.conf ${PKG_SYSCONFDIR}/tuxpaint.conf

.include "../../audio/SDL-mixer/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../devel/SDL_ttf/buildlink2.mk"
.include "../../graphics/SDL-image/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
