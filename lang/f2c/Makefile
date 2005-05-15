# $NetBSD: Makefile,v 1.35 2005/05/15 22:02:27 jlam Exp $

DISTNAME=	f2c-20001205
PKGREVISION=	8
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_LOCAL}

# Note.  the distfile is kept locally because it is
# created "on the fly" by the real master site with
# no version number included.  This makes it difficult
# at best to use the real master site.  The distfile
# was created by:
#   ftp ftp://netlib.bell-labs.com/netlib/f2c.tar
#   tar -xvf f2c.tar f2c/00lastchange.gz
#   gzcat f2c/00lastchange.gz
#
#read what the last change date was.
#
#   mv f2c.tar f2c-yyyymmdd.tar
#   gzip --best f2c-yyyymmdd.tar
MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.netlib.org/f2c/index.html
COMMENT=	Fortran to C compiler including a script to emulate f77

CONFLICTS=	egcs-current-19980608

F2CMAJOR=	0
F2CMINOR=	0
MAKE_ENV+=	F2CMAJOR=${F2CMAJOR} F2CMINOR=${F2CMINOR}
MAKE_ENV+=	LIBOWN=${LIBOWN} LIBGRP=${LIBGRP}
MAKE_ENV+=	AWK=${AWK}
MAKE_ENV+=	ECHO=${ECHO}

WRKSRC=		${WRKDIR}/f2c
USE_LIBTOOL=	yes

PKGSRC_USE_TOOLS+=	gunzip

post-extract:
	@${RM} ${WRKSRC}/index.html
	@${GUNZIP_CMD} ${WRKSRC}/*.gz
	@cd ${WRKSRC} ; ${SH} libf77 ; ${SH} libi77
	@${RM} ${WRKSRC}/src/index.html
	@${MV} ${WRKSRC}/src/.depend  ${WRKSRC}/src/depend.orig
	@${GUNZIP_CMD} ${WRKSRC}/src/*.gz

do-configure:
	@cd ${WRKSRC} && ${CC} -o chktypes chktypes.c
	${WRKSRC}/chktypes -v
	@${CP} -f ${WRKSRC}/libF77/signal1.h0 ${WRKSRC}/libF77/signal1.h
	@${CP} -f ${WRKSRC}/f2c.h ${WRKSRC}/libF77/f2c.h
	@${CP} -f ${WRKSRC}/f2c.h ${WRKSRC}/libI77/f2c.h

.include "../../mk/bsd.prefs.mk"
MAKE_ENV+=	MACHINE_ARCH=${MACHINE_ARCH}


.include "../../mk/bsd.pkg.mk"
