# $NetBSD: Makefile,v 1.1.1.1 2009/12/02 22:32:46 asau Exp $

DISTNAME=	libf2c-20090201
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_LOCAL}	# see notes below

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.netlib.org/f2c/index.html
COMMENT=	f2c Fortran support library

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	egcs-current-19980608 \
		f2c<=20090411

EXTRACT_DIR=	${WRKDIR}/libf2c
WRKSRC=		${EXTRACT_DIR}

USE_BSD_MAKEFILE=	yes
USE_LIBTOOL=	yes
MAKE_FLAGS=	LIBF2CSRCDIR=. MKLTARCHIVE=yes

INSTALLATION_DIRS=	lib include

TEST_TARGET=	test

pre-extract:
	@cd ${WRKDIR} && ${MKDIR} ${EXTRACT_DIR}

post-extract:
	@${CP} ${FILESDIR:Q}/libf2c.mk ${WRKSRC}/Makefile
	@${CP} ${FILESDIR:Q}/ltlib.mk ${WRKSRC}/ltlib.mk
	@${CP} ${FILESDIR:Q}/bsd.init.mk ${WRKSRC}/bsd.init.mk	# pkgsrc lossage
	@${RM} -f ${WRKSRC}/ctype.h	# don't mess with system ctype.h
	@${CP} ${FILESDIR:Q}/chktypes.c ${WRKDIR}

do-test:
	@cd ${WRKDIR} && ${CC} -I libf2c -o chktypes chktypes.c
	${WRKDIR}/chktypes -v

# Notes
#
# Original distfile doesn't carry version information,
# This makes it difficult at best to use the real master site.
# We create our local the distfile:
#   ftp http://www.netlib.org/f2c/libf2c.zip
#   unzip -d tmp libf2c.zip
#   (cd tmp; ls | pax -zwf ../libf2c-yyyymmdd.tar.gz)
#
# Date corresponds to the last libf2c change from:
#   http://www.netlib.org/f2c/changes

.include "../../mk/bsd.pkg.mk"
