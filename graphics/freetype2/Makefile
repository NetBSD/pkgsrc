# $NetBSD: Makefile,v 1.1.1.1 2000/11/27 14:42:19 rh Exp $
#

DISTNAME=	freetype2-beta8
PKGNAME=	freetype2-2.0b8
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=freetype/}			\
		http://freetype.sourceforge.net/pub/freetype/freetype2/	\
		http://gd.tuwien.ac.at/publishing/freetype/freetype2/	\
		http://ftp.funet.fi/pub/mirrors/ftp.freetype.org/freetype2/ \
		http://ftp.sunet.se/pub/text-processing/freetype/freetype2/ \
		ftp://www.nigels.com/pub/freetype/freetype2/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.freetype.org/

USE_GMAKE=	YES
GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

LTCONFIG_OVERRIDE=	${WRKSRC}/builds/unix/ltconfig

post-patch:
	${RM} -f ${LTCONFIG_OVERRIDE} ;				\
	${ECHO} "${RM} -f libtool; ${LN} -s ${LIBTOOL} libtool"	\
		> ${LTCONFIG_OVERRIDE} ;			\
	${CHMOD} +x ${LTCONFIG_OVERRIDE} ;			\

do-configure:
		cd ${WRKSRC}/builds/unix && ${SETENV}			\
			CC="${CC}" CFLAGS="${CFLAGS}"			\
			CXX="${CXX}" CXXFLAGS="${CXXFLAGS}"		\
			INSTALL="`${TYPE} ${INSTALL} | ${AWK} '{ print $$NF }'` -c -o ${BINOWN} -g ${BINGRP}"		\
			INSTALL_DATA="${INSTALL_DATA}"			\
			INSTALL_PROGRAM="${INSTALL_PROGRAM}"		\
			INSTALL_SCRIPT="${INSTALL_SCRIPT}"		\
			${CONFIGURE_ENV} ${CONFIGURE_SCRIPT}		\
				${CONFIGURE_ARGS}			\
				--includedir=${PREFIX}/include/freetype2
		cd ${WRKSRC} && ${LN} -s builds/unix/unix.mk config.mk

.include "../../mk/bsd.pkg.mk"
