# $NetBSD: Makefile,v 1.7 2001/06/26 22:02:26 zuntum Exp $
#

DISTNAME=	freetype-2.0.3
PKGNAME=	freetype2-2.0.3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=freetype/}			\
		http://freetype.sourceforge.net/pub/freetype/freetype2/	\
		http://gd.tuwien.ac.at/publishing/freetype/freetype2/	\
		http://ftp.funet.fi/pub/mirrors/ftp.freetype.org/freetype2/ \
		http://ftp.sunet.se/pub/text-processing/freetype/freetype2/ \
		ftp://www.nigels.com/pub/freetype/freetype2/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.freetype.org/
COMMENT=	font rendering engine and library API

USE_BUILDLINK_ONLY=	YES
USE_CONFIG_WRAPPER=	YES
REPLACE_BUILDLINK=	freetype-config
CHECK_FREETYPE2=	YES
USE_GMAKE=		YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/builds/unix/ltconfig

.include "../../mk/bsd.prefs.mk"

.if ${HAVE_BUILTIN_FREETYPE2} != "NO"
IGNORE=		"FreeType2 has already been installed as part of XFree86-4.x"
.endif

post-patch:
	${RM} -f ${LTCONFIG_OVERRIDE} ;				\
	${ECHO} "${RM} -f libtool; ${LN} -s ${LIBTOOL} libtool"	\
		> ${LTCONFIG_OVERRIDE} ;			\
	${CHMOD} +x ${LTCONFIG_OVERRIDE} ;			\

do-configure:
		cd ${WRKSRC}/builds/unix && ${SETENV}			\
			CC="${CC}" CFLAGS="${CFLAGS}"			\
			CXX="${CXX}" CXXFLAGS="${CXXFLAGS}"		\
			INSTALL="${INSTALL_PROGRAM}"			\
			INSTALL_DATA="${INSTALL_DATA}"			\
			INSTALL_PROGRAM="${INSTALL_PROGRAM}"		\
			INSTALL_SCRIPT="${INSTALL_SCRIPT}"		\
			${CONFIGURE_ENV} ${CONFIGURE_SCRIPT}		\
				${CONFIGURE_ARGS}			\
				--includedir=${PREFIX}/include
		cd ${WRKSRC} && ${LN} -s builds/unix/unix.mk config.mk

.include "../../mk/bsd.pkg.mk"
