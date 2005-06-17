# $NetBSD: Makefile,v 1.13 2005/06/17 04:49:47 jlam Exp $
#

DISTNAME=		sr233
PKGNAME=		sr-2.3.3
PKGREVISION=		6
CATEGORIES=		lang parallel
MASTER_SITES=		ftp://ftp.cs.arizona.edu/sr/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		is@NetBSD.org
HOMEPAGE=		http://www.cs.arizona.edu/sr/
COMMENT=		The SR language compiler and run time system

WRKSRC= ${WRKDIR}

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
			-${MKDIR} ${PREFIX}/lib/sr

post-install:
			${INSTALL_PROGRAM} ${WRKSRC}/csw/cstest ${PREFIX}/bin
			${INSTALL_DATA_DIR} ${PREFIX}/share/doc/sr
			cd ${WRKSRC}/ps && \
				${INSTALL_DATA} *.ps ${PREFIX}/share/doc/sr

.include "../../mk/bsd.pkg.mk"
