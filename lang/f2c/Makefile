# $NetBSD: Makefile,v 1.18 2001/11/29 01:12:38 hubertf Exp $

DISTNAME=	f2c-20001205
PKGREVISION=	4
WRKSRC=		${WRKDIR}/f2c
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
#   gzip f2c-yyyymmdd.tar
MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://www.netlib.org/f2c/index.html
COMMENT=	Fortran to C compiler including a script to emulate f77

CONFLICTS=	egcs-current-19980608

F2CMAJOR=	0
F2CMINOR=	0
MAKE_ENV+=	F2CMAJOR=${F2CMAJOR} F2CMINOR=${F2CMINOR}
PLIST_SUBST+=	F2CMAJOR=${F2CMAJOR} F2CMINOR=${F2CMINOR}

USE_BUILDLINK_ONLY=	# defined

post-extract:
	@${RM} ${WRKSRC}/index.html
	@${GUNZIP_CMD} ${WRKSRC}/*.gz
	@cd ${WRKSRC} ; ${SH} libf77 ; ${SH} libi77
	@${RM} ${WRKSRC}/src/index.html
	@${MV} ${WRKSRC}/src/.depend  ${WRKSRC}/src/depend.orig
	@${GUNZIP_CMD} ${WRKSRC}/src/*.gz

post-patch:
	@cd ${WRKSRC} && ${CC} -o chktypes chktypes.c
	${WRKSRC}/chktypes -v
	@${CP} -f ${WRKSRC}/libF77/signal1.h0 ${WRKSRC}/libF77/signal1.h
	@${CP} -f ${WRKSRC}/f2c.h ${WRKSRC}/libF77/f2c.h
	@${CP} -f ${WRKSRC}/f2c.h ${WRKSRC}/libI77/f2c.h
	@${ECHO} "major=${F2CMAJOR}" > ${WRKSRC}/libF77/shlib_version
	@${ECHO} "minor=${F2CMINOR}" >> ${WRKSRC}/libF77/shlib_version
	@${ECHO} "major=${F2CMAJOR}" > ${WRKSRC}/libI77/shlib_version
	@${ECHO} "minor=${F2CMINOR}" >> ${WRKSRC}/libI77/shlib_version

# for OBJECT_FMT
.include "../../mk/bsd.prefs.mk"

.if (${OBJECT_FMT} == "ELF")
post-install:
	cd ${PREFIX}/lib && ${LN} -fs libf2c.so.${F2CMAJOR}.${F2CMINOR}  libf2c.so.${F2CMAJOR}
	cd ${PREFIX}/lib && ${LN} -fs libf2c.so.${F2CMAJOR}.${F2CMINOR}  libf2c.so

.endif

.include "../../mk/bsd.pkg.mk"
