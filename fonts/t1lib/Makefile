# $NetBSD: Makefile,v 1.16 2004/10/03 00:14:42 tv Exp $
#

DISTNAME=	t1lib-5.0.2
PKGREVISION=	3
CATEGORIES=	fonts devel graphics
MASTER_SITES=	${MASTER_SITE_SUNSITE:=libs/graphics/} \
		ftp://ftp.foolabs.com/pub/xpdf/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Library for generating bitmaps from Adobe Type 1 fonts

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_X11=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ac-tools/ltconfig

ALL_TARGET=	without_doc

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
DATADIR=	${PREFIX}/share/${PKGBASE}

CONF_FILES=	${EGDIR}/t1lib.config.sample ${DATADIR}/t1lib.config
CONF_FILES+=	${EGDIR}/FontDataBase ${DATADIR}/FontDataBase

pre-build:
	${FIND} ${WRKSRC} -name "*.orig" -print | ${XARGS} ${RM}

post-install:
	${INSTALL_DATA_DIR} ${DATADIR}
	cd ${WRKSRC};							\
	${PAX} -rw Fonts ${DATADIR};					\
	${CHMOD} go+r ${DATADIR}/Fonts/enc/IsoLatin2.enc;		\
	${PAX} -rw -s "/doc/${PKGBASE}/" doc ${PREFIX}/share/doc

	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}/examples;						\
	${PAX} -rw FontDataBase t1example1.c t1lib.config ${EGDIR}
	${SED}	${FILES_SUBST_SED}					\
		${FILESDIR}/t1lib.config.sample > ${EGDIR}/t1lib.config.sample

.include "../../mk/bsd.pkg.mk"
