# $NetBSD: Makefile,v 1.33 2005/12/11 09:40:45 wiz Exp $
#

DISTNAME=	tuxpaint-0.9.14
PKGREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tuxpaint/} \
		ftp://ftp.sonic.net/pub/users/nbs/unix/x/tuxpaint/source/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.newbreedsoftware.com/tuxpaint/
COMMENT=	Drawing program for small children

USE_TOOLS+=		gmake
USE_PKGINSTALL=		YES
USE_PKGLOCALEDIR=	YES
MANCOMPRESSED=		YES

BUILDLINK_DEPENDS.SDL_mixer+=	SDL_mixer>=1.2.6
BUILDLINK_DEPENDS.SDL_ttf+=	SDL_ttf>=2.0.7
BUILDLINK_DEPENDS.SDL_image+=	SDL_image>=1.2.4

CONFLICTS+=		tuxpaint-stamps<2003.12.23

MAKE_ENV+=		CONFDIR=${PKG_SYSCONFDIR:Q} CP=${CP:Q} CHMOD=${CHMOD:Q}
EGDIR=			${PREFIX}/share/examples/tuxpaint
CONF_FILES=		${EGDIR}/tuxpaint.conf ${PKG_SYSCONFDIR}/tuxpaint.conf

# this uses iconv and png functions directly, so link against them
# explicitly.
MAKE_ENV+=		LIBS=${LIBS:M*:Q}
LIBS+=			-liconv
LIBS+=			-lpng

post-install:
	-${FIND} ${PREFIX}/share/doc/tuxpaint -name CVS -exec ${RM} -r {} \; 2>/dev/null
	-${RMDIR} ${PREFIX}/share/doc/tuxpaint/cz
	-${FIND} ${PREFIX}/share/tuxpaint -name CVS -exec ${RM} -r {} \; 2>/dev/null

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
