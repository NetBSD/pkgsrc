# $NetBSD: Makefile,v 1.7 2005/12/05 20:50:26 rillig Exp $
#

PKGNAME=		mpd-1.0.1
DISTNAME=		mpd.1.0.1
PKGREVISION=		4
CATEGORIES=		lang parallel
MASTER_SITES=		http://www.cs.arizona.edu/mpd/download/
EXTRACT_SUFX=		.tgz
DIST_SUBDIR=		mpd-language

CONFLICTS+=		musicpd-[0-9]*

MAINTAINER=		is@NetBSD.org
HOMEPAGE=		http://www.cs.arizona.edu/mpd/
COMMENT=		The MPD language compiler and run time system

ONLY_FOR_PLATFORM=     NetBSD-[2-9]*-*


TEST_TARGET=		verify

.include "../../mk/x11.buildlink3.mk"

pre-configure:
			${MV} ${WRKSRC}/Configuration \
				${WRKSRC}/Configuration.template
			${SED}	-e 's,_LOCALBASE_,${LOCALBASE},g' \
				-e 's,_WRKSRC_,${WRKSRC},g' \
				-e 's,_XINC_,${X11BASE}/include,g' \
				-e 's,_XLIB_,${X11BASE}/lib,g' \
				${WRKSRC}/Configuration.template \
				> ${WRKSRC}/Configuration

pre-install:
			-${MKDIR} ${PREFIX}/lib/mpd

post-install:
			${INSTALL_PROGRAM} ${WRKSRC}/csw/cstest ${PREFIX}/bin/mpd-cstest
			${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mpd
			${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/mpd
			${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/mpd
			${INSTALL_DATA} ${WRKSRC}/doc/cairn.jpg ${PREFIX}/share/doc/html/mpd
			${INSTALL_DATA} ${WRKSRC}/doc/install.html ${PREFIX}/share/doc/html/mpd
			${INSTALL_DATA} ${WRKSRC}/doc/release.html ${PREFIX}/share/doc/html/mpd

.include "../../mk/bsd.pkg.mk"
