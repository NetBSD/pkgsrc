# $NetBSD: Makefile,v 1.1.1.1 2000/02/15 19:43:22 pooka Exp $

DISTNAME=	bwbasic-2.20
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.rahul.net/pub/rhn/
DISTFILES=	bwbasic-2.20.tar.Z \
		bwb-2.20-patch01.tar.Z.uu.txt bwb-2.20-patch02.tar.Z.uu.txt

MAINTAINER=	jspath@bcpl.net

GNU_CONFIGURE=	yes
EXTRACT_ONLY=	bwbasic-2.20.tar.Z

# The patches come in a totally bizarre format; we have to 
# uudecode them, unpack the resulting tarfile, and then replace
# some of the original files.
# Make a manual page from the doc file.

pre-patch:
	${MKDIR} ${WRKSRC}/tmp
	cd ${WRKSRC}/tmp ; \
	uudecode ${DISTDIR}/bwb-2.20-patch01.tar.Z.uu.txt ; \
	${GTAR} -xzf bwb-2.20-patch01.tar.Z ; \
	${MV} bwb-2.20-patch01/* ${WRKSRC}
	cd ${WRKSRC}/tmp ; \
	uudecode ${DISTDIR}/bwb-2.20-patch02.tar.Z.uu.txt ; \
	${GTAR} -xzf bwb-2.20-patch02.tar.Z ; \
	${MV} bwb-2.20-patch02/* ${WRKSRC}
	${RM} -rf ${WRKSRC}/tmp
	${CP} -pf ${WRKSRC}/bwbasic.doc ${WRKSRC}/bwbasic.1

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/bwbasic
	${INSTALL_DATA} ${WRKSRC}/bwbasic.doc ${PREFIX}/share/bwbasic/
	${CP} -r ${WRKSRC}/bwbtest ${PREFIX}/share/bwbasic/
	${INSTALL_MAN} ${WRKSRC}/bwbasic.1 ${PREFIX}/man/man1/bwbasic.1

.include "../../mk/bsd.pkg.mk"
