# $NetBSD: Makefile,v 1.32 2002/09/06 09:18:41 zuntum Exp $

DISTNAME=		Wine-20020804
PKGNAME=		${DISTNAME:S/W/w/}
WRKSRC=			${WRKDIR}/${PKGNAME}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUNSITE:=ALPHA/wine/development/}

MAINTAINER=		junyoung@netbsd.org
HOMEPAGE=		http://www.winehq.com/
COMMENT=		Free implementation of Windows on Unix (still alpha)

CONFLICTS=		rewind-[0-9]*

ONLY_FOR_PLATFORM=	NetBSD-1.5Z*-i386 NetBSD-1.[6-9]*-i386

USE_BUILDLINK_ONLY=	YES
USE_GMAKE=		YES
USE_PERL5=		run
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-curses

REPLACE_PERL=		tools/winedump/function_grep.pl tools/winemaker

# The Wine configure script has problems locating the freetype-config
# script and the libraries in the buildlink directory, so explicitly
# set the location of freetype-config and prepend all of the LDFLAGS
# necessary to link against the libraries.
#
CONFIGURE_ENV+=		ft_devel=${FREETYPE_CONFIG}
CONFIGURE_ENV+=		X_LIBS="${LDFLAGS}"
LIBS+=			${LDFLAGS}

CONFIGURE_ENV+=		ac_cv_path_ARTSCCONFIG=no
CONFIGURE_ENV+=		ac_cv_prog_sane_devel=no

.include "../../mk/bsd.prefs.mk"

.if defined(USE_CUPS) && (${USE_CUPS} == YES)
.include "../../print/cups/buildlink.mk"
BUILD_DEFS+=		USE_CUPS
.endif

EGDIR=			${PREFIX}/share/examples/wine

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
