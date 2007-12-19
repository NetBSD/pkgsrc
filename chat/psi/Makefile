# $NetBSD: Makefile,v 1.50 2007/12/19 13:19:38 jdolecek Exp $

PSI_VERSION=	0.11
DISTNAME=	psi-${PSI_VERSION}
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=psi/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jdolecek@NetBSD.org
HOMEPAGE=	http://psi-im.org/
COMMENT=	PSI Jabber Client

DEPENDS+=	qca-ossl>=2.0.0beta3:../../security/qca-ossl

DIST_SUBDIR=	${DISTNAME}-20071115-1
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${LANG_FILES}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
HAS_CONFIGURE=	yes

CONFIG_SHELL=	${SH}

CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--qtdir=${QTDIR:Q}
CONFIGURE_ARGS+=	--disable-bundled-qca
CONFIGURE_ARGS+=	--with-zlib-inc=${BUILDLINK_PREFIX.zlib}/include
CONFIGURE_ARGS+=	--with-zlib-lib=${BUILDLINK_PREFIX.zlib}/lib

# no lang files for 0.13 yet
#LANG_FILES=	psi_bg.qm psi_ca.qm psi_eo.qm psi_es.qm psi_fr.qm	\
#		psi_hu.qm psi_mk.qm psi_nl.qm psi_pl.qm psi_pt.qm	\
#		psi_pt_BR.qm psi_sk.qm psi_sl.qm psi_vi.qm psi_zh.qm
LANG_FILES=

.for l in ${LANG_FILES}
SITES.${l}=	http://psi-im.org/files/translation/${PSI_VERSION}/
.endfor

INSTALLATION_DIRS=	bin share/psi share/doc/psi

# custom install targets, we don't want psi to install the desktop & icon
# stuff
do-install:
	cd ${WRKSRC}/src && ${MAKE} install_target install_sharedfiles
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/psi
.for f in ${LANG_FILES}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${f} ${PREFIX}/share/psi
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/psi ${PREFIX}/bin/psi

.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/qca/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
