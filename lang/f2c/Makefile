# $NetBSD: Makefile,v 1.11 2001/03/05 16:41:58 wiz Exp $

DISTNAME=	f2c-20001205
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
	@${CP} ${WRKSRC}/f2c.h ${WRKSRC}/libF77/f2c.h
	@${CP} ${WRKSRC}/f2c.h ${WRKSRC}/libI77/f2c.h

.include "../../mk/bsd.pkg.mk"
