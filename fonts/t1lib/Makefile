# $NetBSD: Makefile,v 1.2 2002/09/19 00:51:21 jlam Exp $
#

DISTNAME=	t1lib-1.1.1
WRKSRC=		${WRKDIR}/T1-1.1.1
CATEGORIES=	fonts devel graphics
MASTER_SITES=	${MASTER_SITE_SUNSITE:=libs/graphics/} \
		ftp://ftp.neuroinformatik.ruhr-uni-bochum.de/pub/software/t1lib/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.neuroinformatik.ruhr-uni-bochum.de/ini/PEOPLE/rmz/t1lib/t1lib.html
COMMENT=	Library for generating bitmaps from Adobe Type 1 fonts

USE_BUILDLINK2=		# defined
GNU_CONFIGURE=		# defined
USE_GMAKE=		# defined
USE_X11BASE=		# defined
USE_LIBTOOL=		# defined
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

ALL_TARGET=	without_doc

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
DATADIR=	${PREFIX}/share/${PKGBASE}

CONF_FILES=	${EGDIR}/t1lib.config.netbsd ${DATADIR}/t1lib.config
CONF_FILES+=	${EGDIR}/FontDataBase ${DATADIR}/FontDataBase

post-install:
	${INSTALL_DATA_DIR} ${DATADIR}
	cd ${WRKSRC};							\
	${PAX} -rw Fonts ${DATADIR};					\
	${CHMOD} go+r ${DATADIR}/Fonts/enc/IsoLatin2.enc;		\
	${PAX} -rw -s "/doc/t1lib/" doc ${PREFIX}/share/doc

	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}/examples;						\
	${PAX} -rw FontDataBase t1example1.c t1lib.config ${EGDIR}
	${SED}	-e "s|@@X11BASE@@|${X11BASE}|g"				\
		-e "s|@@LOCALBASE@@|${LOCALBASE}|g"			\
		-e "s|@@PREFIX@@|${PREFIX}|g"				\
		${FILESDIR}/t1lib.config.netbsd > ${EGDIR}/t1lib.config.netbsd

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
