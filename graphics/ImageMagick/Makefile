# $NetBSD: Makefile,v 1.69 2001/06/20 22:24:44 jlam Exp $

DISTNAME=		ImageMagick-5.2.8
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_LOCAL}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.simplesystems.org/ImageMagick/
COMMENT=		Package for display and interactive manipulation of images

CONFLICTS=		geomview-*    # both have a program named 'animate'

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
USE_X11=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

# Avoid compiler bug on "arm32"
.if (${MACHINE_ARCH} == arm32)
CFLAGS=			-O
.endif

.include "../../mk/bsd.prefs.mk"
.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../graphics/tiff/buildlink.mk"

# For things for which we do not specify an explicit dependency above, disable
# so that we don't cause implicit "hidden" dependencies.  Users may reenable
# any of these manually as desired (PerlMagick should probably be a separate
# pkg, however).
CONFIGURE_ARGS+=	--without-perl --without-dps --without-fpx \
			--without-hdf --without-jbig --without-threads \
			--without-ttf --without-wmf --without-xml

# Fix references to libbz2 functions on NetBSD.
.if (${OPSYS} == "NetBSD")
post-extract:
	@cd ${WRKSRC};							\
	for file in ${CONFIGURE_SCRIPT} coders/miff.c; do		\
		${MV} -f $${file} $${file}.presubst;			\
		${SED} -e "s|BZ2_||g" $${file}.presubst > $${file};	\
		${RM} -f $${file}.presubst;				\
	done;								\
	${CHMOD} +x ${CONFIGURE_SCRIPT}
.endif

# Fix config scripts by removing buildlink directory references.
post-build:
	@cd ${WRKSRC};							\
	config_scripts="Magick++/bin/Magick++-config magick/Magick-config"; \
	for file in $${config_scripts}; do				\
		${MV} -f $${file} $${file}.fixme;			\
		${SED}	-e "s|-I${BUILDLINK_DIR}/|-I${LOCALBASE}/|g"	\
			-e "s|-L${BUILDLINK_DIR}/|-L${LOCALBASE}/|g"	\
			$${file}.fixme > $${file};			\
		${RM} -f $${file}.fixme;				\
		${CHMOD} +x $${file};					\
	done

post-install:
	${INSTALL_DATA} ${WRKSRC}/Copyright.txt ${WRKSRC}/QuickStart.txt \
		${PREFIX}/share/ImageMagick

.include "../../mk/bsd.pkg.mk"
