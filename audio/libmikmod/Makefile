# $NetBSD: Makefile,v 1.10 2001/06/19 16:00:05 jlam Exp $

DISTNAME=		libmikmod-3.1.9
CATEGORIES=		audio
MASTER_SITES=		http://mikmod.darkorb.net/libmikmod/

MAINTAINER=		kuebart@mathematik.uni-ulm.de
HOMEPAGE=		http://mikmod.darkorb.net/
COMMENT=		MikMod Sound Library

USE_GMAKE=		# defined
USE_GTEXINFO=		# defined
GNU_CONFIGURE=		# defined
USE_LIBTOOL=		# defined

USE_BUILDLINK_ONLY=	# defined
USE_CONFIG_WRAPPER=	# defined

CONFIGURE_ARGS+=	--disable-threads
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

pre-build:
	${RM} -f ${WRKSRC}/docs/mikmod.info*

# Fix config scripts by removing buildlink directory references.
post-build:
	@cd ${WRKSRC};							\
	config_scripts="libmikmod-config";				\
	for file in $${config_scripts}; do				\
		${MV} -f $${file} $${file}.fixme;			\
		${SED}	-e "s|-I${BUILDLINK_DIR}/|-I${LOCALBASE}/|g"	\
			-e "s|-L${BUILDLINK_DIR}/|-L${LOCALBASE}/|g"	\
			$${file}.fixme > $${file};			\
		${RM} -f $${file}.fixme;				\
		${CHMOD} +x $${file};					\
	done

.include "../../audio/esound/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
