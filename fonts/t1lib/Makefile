# $NetBSD: Makefile,v 1.22 2005/06/15 04:43:09 jlam Exp $
#

DISTNAME=	t1lib-5.0.2
PKGREVISION=	4
CATEGORIES=	fonts devel graphics
MASTER_SITES=	${MASTER_SITE_SUNSITE:=libs/graphics/} \
		ftp://ftp.foolabs.com/pub/xpdf/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Library for generating bitmaps from Adobe Type 1 fonts

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_PKGINSTALL=		YES
USE_TOOLS+=		gmake
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

BUILD_TARGET=	without_doc

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
DATADIR=	${PREFIX}/share/${PKGBASE}

CONF_FILES=	${EGDIR}/t1lib.config.sample ${DATADIR}/t1lib.config
CONF_FILES+=	${EGDIR}/FontDataBase ${DATADIR}/FontDataBase

.include "../../graphics/xpm/buildlink3.mk"

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
