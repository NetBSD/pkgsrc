# $NetBSD: Makefile,v 1.24 2004/10/03 00:14:58 tv Exp $
#

DISTNAME=	tuxpaint-0.9.13
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tuxpaint/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.newbreedsoftware.com/tuxpaint/
COMMENT=	Drawing program for small children

USE_BUILDLINK3=		YES
USE_GNU_TOOLS+=		make
USE_PKGINSTALL=		YES
USE_PKGLOCALEDIR=	YES
MANCOMPRESSED=		YES

CONFLICTS+=		tuxpaint-stamps<2003.12.23

MAKE_ENV+=		CONFDIR="${PKG_SYSCONFDIR}" CP="${CP}" CHMOD="${CHMOD}"
EGDIR=			${PREFIX}/share/examples/tuxpaint
CONF_FILES=		${EGDIR}/tuxpaint.conf ${PKG_SYSCONFDIR}/tuxpaint.conf

post-install:
	-${FIND} ${PREFIX}/share/doc/tuxpaint -name CVS -exec ${RM} -r {} \; 2>/dev/null
	-${FIND} ${PREFIX}/share/tuxpaint -name CVS -exec ${RM} -r {} \; 2>/dev/null

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
