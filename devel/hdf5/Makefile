# $NetBSD: Makefile,v 1.1.1.1 2000/11/24 20:42:59 jtb Exp $
#

DISTNAME=	hdf5-1.2.2
CATEGORIES=	devel
MASTER_SITES=	ftp://hdf.ncsa.uiuc.edu/HDF5/hdf5-1.2.2/src/ \
		ftp://sunsite.doc.ic.ac.uk/packages/HDF5/hdf5-1.2.2/src/

MAINTAINER=	jtb@netbsd.org
HOMEPAGE=	http://hdf.ncsa.uiuc.edu/HDF5/

DEPENDS+= jpeg-[0-9]*:../../graphics/jpeg

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
LIBTOOL_OVERRIDE= ${WRKSRC}/libtool

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/hdf5
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/hdf5/ADGuide
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/hdf5/PSandPDF
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/hdf5/TechNotes
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/hdf5/Tutor
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/hdf5/Tutor/Graphics
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/hdf5/Tutor/examples
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/hdf5/Tutor/examples/java
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/hdf5/XML_DTD
	@(cd ${WRKSRC}/doc/html/;					\
	for f in *.html *.txt *.gif *.jpg *.c *.obj h5s.examples ; do 	\
	${INSTALL_DATA} $$f ${PREFIX}/share/doc/hdf5; 			\
	done)
	${INSTALL_DATA} ${WRKSRC}/doc/html/ADGuide/* 			\
	${PREFIX}/share/doc/hdf5/ADGuide
	${INSTALL_DATA} ${WRKSRC}/doc/html/PSandPDF/*			\
	${PREFIX}/share/doc/hdf5/PSandPDF
	${INSTALL_DATA} ${WRKSRC}/doc/html/TechNotes/*			\
	${PREFIX}/share/doc/hdf5/TechNotes
	@(cd ${WRKSRC}/doc/html/Tutor;					\
	for f in *.html *.txt *.gif *.JPG; do				\
	${INSTALL_DATA} $$f ${PREFIX}/share/doc/hdf5/Tutor/;		\
	done)
	${INSTALL_DATA} ${WRKSRC}/doc/html/Tutor/Graphics/*		\
	${PREFIX}/share/doc/hdf5/Tutor/Graphics/
	@(cd ${WRKSRC}/doc/html/Tutor/examples/ ;			\
	for f in *.c *.f90 ; do						\
	${INSTALL_DATA} $$f ${PREFIX}/share/doc/hdf5/Tutor/examples/ ;	\
	done)
	${INSTALL_DATA} ${WRKSRC}/doc/html/Tutor/examples/java/*	\
	${PREFIX}/share/doc/hdf5/Tutor/examples/java/
	${INSTALL_DATA} ${WRKSRC}/doc/html/XML_DTD/*			\
	${PREFIX}/share/doc/hdf5/XML_DTD

.include "../../mk/bsd.pkg.mk"
