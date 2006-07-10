# $NetBSD: Makefile,v 1.10 2006/07/10 04:04:22 rillig Exp $
#

DISTNAME=		mpd.1.0.1
PKGNAME=		mpd-1.0.1
PKGREVISION=		7
CATEGORIES=		lang parallel
MASTER_SITES=		http://www.cs.arizona.edu/mpd/download/
DIST_SUBDIR=		mpd-language
EXTRACT_SUFX=		.tgz

MAINTAINER=		is@NetBSD.org
HOMEPAGE=		http://www.cs.arizona.edu/mpd/
COMMENT=		The MPD language compiler and run time system

CONFLICTS+=		musicpd-[0-9]*

ONLY_FOR_PLATFORM=	NetBSD-[2-9]*-*


TEST_TARGET=		verify

SUBST_CLASSES+=		mpd
SUBST_STAGE.mpd=	pre-configure
SUBST_MESSAGE.mpd=	Filling out path templates.
SUBST_FILES.mpd=	Configuration
SUBST_SED.mpd=		-e 's,_LOCALBASE_,${LOCALBASE},g'
SUBST_SED.mpd+=		-e 's,_WRKSRC_,${WRKSRC},g'
SUBST_SED.mpd+=		-e 's,_XINC_,${X11BASE}/include,g'
SUBST_SED.mpd+=		-e 's,_XLIB_,${X11BASE}/lib,g'

INSTALLATION_DIRS=	bin lib/mpd man/man1 man/man3 share/doc/mpd

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/csw/cstest ${PREFIX}/bin/mpd-cstest
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/mpd
	${INSTALL_DATA} ${WRKSRC}/doc/cairn.jpg ${PREFIX}/share/doc/mpd
	${INSTALL_DATA} ${WRKSRC}/doc/install.html ${PREFIX}/share/doc/mpd
	${INSTALL_DATA} ${WRKSRC}/doc/release.html ${PREFIX}/share/doc/mpd

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
