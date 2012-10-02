# $NetBSD: Makefile,v 1.22 2012/10/02 20:11:54 asau Exp $
#

DISTNAME=		sr233
PKGNAME=		sr-2.3.3
PKGREVISION=		7
CATEGORIES=		lang parallel
MASTER_SITES=		ftp://ftp.cs.arizona.edu/sr/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		is@NetBSD.org
HOMEPAGE=		http://www.cs.arizona.edu/sr/
COMMENT=		The SR language compiler and run time system

NOT_FOR_PLATFORM=	*-*-x86_64  # site: "doesn't run on 64-bit/AMD64"

MAKE_JOBS_SAFE=		no

USE_TOOLS+=		yacc

WRKSRC= ${WRKDIR}
TEST_TARGET=		verify
AUTO_MKDIRS=		yes

SUBST_CLASSES+=		sr
SUBST_STAGE.sr=		pre-configure
SUBST_FILES.sr=		Configuration
SUBST_SED.sr=		-e 's,_LOCALBASE_,${LOCALBASE},g'
SUBST_SED.sr+=		-e 's,_WRKSRC_,${WRKSRC},g'
SUBST_SED.sr+=		-e 's,_XINC_,${X11BASE}/include,g'
SUBST_SED.sr+=		-e 's,_XLIB_,${X11BASE}/lib,g'

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/csw/cstest ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC}/ps && ${INSTALL_DATA} *.ps ${DESTDIR}${PREFIX}/share/doc/sr

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
