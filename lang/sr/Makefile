# $NetBSD: Makefile,v 1.6 2005/03/08 13:49:49 is Exp $
#

DISTNAME=		sr233
PKGNAME=		sr-2.3.3
PKGREVISION=		2
CATEGORIES=		lang parallel
MASTER_SITES=		ftp://ftp.cs.arizona.edu/sr/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		is@NetBSD.org
HOMEPAGE=		http://www.cs.arizona.edu/sr/
COMMENT=		The SR language compiler and run time system

WRKSRC= ${WRKDIR}

ONLY_FOR_PLATFORM=     NetBSD-[2-9]*-*

USE_X11=		yes
USE_BUILDLINK3=		yes

TEST_TARGET=		verify

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
			-${MKDIR} ${LOCALBASE}/lib/sr

post-install:
			${INSTALL_PROGRAM} ${WRKSRC}/csw/cstest ${PREFIX}/bin
			${INSTALL_DATA_DIR} ${PREFIX}/share/doc/sr
			cd ${WRKSRC}/ps && \
				${INSTALL_DATA} *.ps ${PREFIX}/share/doc/sr

.include "../../mk/bsd.pkg.mk"
