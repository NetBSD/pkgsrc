# $NetBSD: Makefile,v 1.1.1.1 2002/04/20 08:10:29 rh Exp $

DISTNAME=		rewind-20020420
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_LOCAL}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://rewind.sourceforge.net/
COMMENT=		BSD/X11 licenced fork of Wine (Windows on Unix)

CONFLICTS=		wine-[0-9]*

ONLY_FOR_PLATFORM=	NetBSD-1.5Z*-i386 NetBSD-1.[6-9]*-i386

USE_BUILDLINK_ONLY=	YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-curses

# The rewind configure script has problems locating the freetype-config
# script and the libraries in the buildlink directory, so explicitly
# set the location of freetype-config and prepend all of the LDFLAGS
# necessary to link against the libraries.
#
CONFIGURE_ENV+=		ft_devel=${FREETYPE_CONFIG}
CONFIGURE_ENV+=		X_LIBS="${LDFLAGS}"
LIBS+=			${LDFLAGS}

.include "../../mk/bsd.prefs.mk"

.if defined(USE_CUPS) && (${USE_CUPS} == YES)
.include "../../print/cups/buildlink.mk"
BUILD_DEFS+=		USE_CUPS
.endif

EGDIR=			${PREFIX}/share/examples/rewind

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}/documentation/samples;				\
	${INSTALL_DATA} config ${EGDIR}/wine.conf;			\
	${INSTALL_DATA} generic.ppd ${EGDIR}/generic.ppd;		\
	${INSTALL_DATA} system.ini ${EGDIR}/system.ini

.include "../../graphics/Mesa/buildlink.mk"
.include "../../graphics/freetype2/buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
