# $NetBSD: Makefile,v 1.16 2007/12/01 12:49:05 rillig Exp $
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

WRKSRC= ${WRKDIR}
TEST_TARGET=		verify
INSTALLATION_DIRS_FROM_PLIST=yes

SUBST_CLASSES+=		sr
SUBST_STAGE.sr=		pre-configure
SUBST_FILES.sr=		Configuration
SUBST_SED.sr=		-e 's,_LOCALBASE_,${LOCALBASE},g'
SUBST_SED.sr+=		-e 's,_WRKSRC_,${WRKSRC},g'
SUBST_SED.sr+=		-e 's,_XINC_,${X11BASE}/include,g'
SUBST_SED.sr+=		-e 's,_XLIB_,${X11BASE}/lib,g'

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/csw/cstest ${PREFIX}/bin
	cd ${WRKSRC}/ps && ${INSTALL_DATA} *.ps ${PREFIX}/share/doc/sr

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
