# $NetBSD: Makefile,v 1.17 2012/10/02 20:11:46 asau Exp $
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

MAKE_JOBS_SAFE=		no

CONFLICTS+=		musicpd-[0-9]*

ONLY_FOR_PLATFORM=	NetBSD-[2-9]*-*
NOT_FOR_PLATFORM=	*-*-x86_64  # as per lang/sr


TEST_TARGET=		verify

DP=			${DESTDIR}${PREFIX}

SUBST_CLASSES+=		mpd
SUBST_STAGE.mpd=	pre-configure
SUBST_MESSAGE.mpd=	Filling out path templates.
SUBST_FILES.mpd=	Configuration
SUBST_SED.mpd=		-e 's,_LOCALBASE_,${LOCALBASE},g'
SUBST_SED.mpd+=		-e 's,_WRKSRC_,${WRKSRC},g'
SUBST_SED.mpd+=		-e 's,_XINC_,${X11BASE}/include,g'
SUBST_SED.mpd+=		-e 's,_XLIB_,${X11BASE}/lib,g'

INSTALLATION_DIRS=	bin lib/mpd ${PKGMANDIR}/man1 ${PKGMANDIR}/man3 \
			${PKGMANDIR}/man5 share/doc/mpd

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/csw/cstest ${DP}/bin/mpd-cstest
	${INSTALL_DATA} ${WRKSRC}/README ${DP}/share/doc/mpd
	${INSTALL_DATA} ${WRKSRC}/doc/cairn.jpg ${DP}/share/doc/mpd
	${INSTALL_DATA} ${WRKSRC}/doc/install.html ${DP}/share/doc/mpd
	${INSTALL_DATA} ${WRKSRC}/doc/release.html ${DP}/share/doc/mpd

.include "../..//x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
