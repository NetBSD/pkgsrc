# $NetBSD: Makefile,v 1.12 2001/08/29 22:41:16 jlam Exp $

DISTNAME=		fnlib-0.5
CATEGORIES=		x11 graphics
MASTER_SITES=		ftp://ftp.enlightenment.org/pub/e/enlightenment/libs/

MAINTAINER=		root@garbled.net
COMMENT=		color font rendering library for X11R6

USE_BUILDLINK_ONLY=	YES
USE_X11BASE=		# defined
GNU_CONFIGURE=		# defined

USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

# Remove -I$(includedir) from the INCLUDES passed to the compiler as this
# defeats buildlink.
#
post-patch:
	cd ${WRKSRC};							\
	files=`${FIND} . -name "Makefile.in" -print`;			\
	for file in $${files}; do					\
		${MV} -f $${file} $${file}.fixme;			\
		${SED} -e "/^INCLUDES.*=.*/s|[  ]*-I\$$(includedir)||"	\
			$${file}.fixme > $${file};			\
		${RM} $${file}.fixme;					\
	done

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/fnlib
	${INSTALL_DATA} ${WRKSRC}/doc/fontinfo.README ${PREFIX}/share/doc/fnlib

.include "../../graphics/imlib/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
