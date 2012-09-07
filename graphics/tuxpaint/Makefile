# $NetBSD: Makefile,v 1.66 2012/09/07 19:16:54 adam Exp $
#

DISTNAME=	tuxpaint-0.9.17
PKGREVISION=	19
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tuxpaint/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tuxpaint.org/
COMMENT=	Drawing program for small children

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake msgfmt pkg-config
USE_PKGLOCALEDIR=	YES
MANCOMPRESSED=		YES

BUILDLINK_API_DEPENDS.SDL_mixer+=	SDL_mixer>=1.2.6
BUILDLINK_API_DEPENDS.SDL_ttf+=	SDL_ttf>=2.0.7
BUILDLINK_API_DEPENDS.SDL_image+=	SDL_image>=1.2.4

CONFLICTS+=		tuxpaint-stamps<2003.12.23

BROKEN_GETTEXT_DETECTION=	yes

PKG_SYSCONFSUBDIR=	tuxpaint
MAKE_ENV+=		CONFDIR=${PKG_SYSCONFDIR:Q} CP=${CP:Q} CHMOD=${CHMOD:Q}
EGDIR=			${PREFIX}/share/examples/tuxpaint
CONF_FILES=		${EGDIR}/tuxpaint.conf ${PKG_SYSCONFDIR}/tuxpaint.conf

INSTALL_MAKE_FLAGS+=	PKG_ROOT=${DESTDIR}

# this uses iconv and png functions directly, so link against them
# explicitly.
MAKE_ENV+=		LIBS=${LIBS:M*:Q}
LIBS+=			-liconv
LIBS+=			-lpng

post-install:
	-${FIND} ${DESTDIR}${PREFIX}/share/doc/tuxpaint -name CVS -exec ${RM} -r {} \; 2>/dev/null
	-${FIND} ${DESTDIR}${PREFIX}/share/tuxpaint -name CVS -exec ${RM} -r {} \; 2>/dev/null

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../print/libpaper/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
