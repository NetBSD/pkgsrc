# $NetBSD: Makefile,v 1.7 2001/06/26 10:26:24 zuntum Exp $
#

DISTNAME=	smpeg-0.4.3
CATEGORIES=	devel
MASTER_SITES=	ftp://sunsite.auc.dk/pub/os/linux/loki/open-source/smpeg/ \
		ftp://ftp.linuxgames.com/loki/open-source/smpeg/

MAINTAINER=	wulf@netbsd.org
HOMEPAGE=	http://www.lokigames.com/development/smpeg.php3
COMMENT=	SDL MPEG Player Library

USE_BUILDLINK_ONLY=	YES
USE_CONFIG_WRAPPER=	YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

# Fix config scripts by removing buildlink directory references.
post-build:
	@cd ${WRKSRC};							\
	config_scripts="smpeg-config";					\
	for file in $${config_scripts}; do				\
	${MV} -f $${file} $${file}.fixme;				\
		${SED}  -e "s|-I${BUILDLINK_DIR}/|-I${LOCALBASE}/|g"	\
		-e "s|-L${BUILDLINK_DIR}/|-L${LOCALBASE}/|g"		\
			$${file}.fixme > $${file};			\
		${RM} -f $${file}.fixme;				\
		${CHMOD} +x $${file};					\
	done

.include "../../devel/SDL/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
