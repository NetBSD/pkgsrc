# $NetBSD: Makefile,v 1.30 2006/02/05 23:09:11 joerg Exp $

DISTNAME=	t1lib-5.1.0
PKGREVISION=	5
CATEGORIES=	fonts devel graphics
MASTER_SITES=	${MASTER_SITE_SUNSITE:=libs/graphics/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Library for generating bitmaps from Adobe Type 1 fonts

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

BUILD_TARGET=	without_doc

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
DATADIR=	${PREFIX}/share/${PKGBASE}

CONF_FILES=	${EGDIR}/t1lib.config.sample ${DATADIR}/t1lib.config
CONF_FILES+=	${EGDIR}/FontDataBase ${DATADIR}/FontDataBase

.include "../../graphics/xpm/buildlink3.mk"

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	t1lib.config.sample
SUBST_SED.paths=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.paths+=	-e 's,@LOCALBASE@,${LOCALBASE},g'
SUBST_STAGE.paths=	post-patch

post-extract:
	${CP} ${FILESDIR}/t1lib.config.sample ${WRKSRC}

pre-build:
	${FIND} ${WRKSRC} -name "*.orig" -print | ${XARGS} ${RM}

post-install:
	${INSTALL_DATA_DIR} ${DATADIR}
	cd ${WRKSRC};							\
	${PAX} -rw Fonts ${DATADIR};					\
	${CHMOD} go+r ${DATADIR}/Fonts/enc/IsoLatin2.enc;		\
	${PAX} -rw -s "/doc/${PKGBASE}/" doc ${PREFIX}/share/doc

	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/t1lib.config.sample ${EGDIR}
	cd ${WRKSRC}/examples;						\
	${PAX} -rw FontDataBase t1example1.c t1lib.config ${EGDIR}

.include "../../mk/bsd.pkg.mk"
