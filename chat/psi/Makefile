# $NetBSD: Makefile,v 1.98 2020/06/02 08:23:20 adam Exp $

DISTNAME=	psi-1.4
PKGREVISION=	8
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=psi/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://psi-im.org/
COMMENT=	Psi XMPP/Jabber Client
LICENSE=	gnu-gpl-v2

DEPENDS+=	qca2-qt5-ossl>=2.0.0beta3:../../security/qca2-qt5-ossl

DIST_SUBDIR=	${DISTNAME}
DISTFILES=	${DEFAULT_DISTFILES}

USE_TOOLS+=	gmake unzip pkg-config
USE_LANGUAGES=	c c++03
USE_LIBTOOL=	yes
HAS_CONFIGURE=	yes

CONFIG_SHELL=	${SH}

CONFIGURE_ARGS+=	--qtselect=5
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--qtdir=${QTDIR}
CONFIGURE_ARGS+=	--with-zlib-inc=${BUILDLINK_PREFIX.zlib}/include
CONFIGURE_ARGS+=	--with-zlib-lib=${BUILDLINK_PREFIX.zlib}/lib
CONFIGURE_ARGS+=	--with-qca-lib=${BUILDLINK_PREFIX.qca2-qt5}/lib
CONFIGURE_ARGS+=	--with-qca-inc=${BUILDLINK_PREFIX.qca2-qt5}/include

#
# a group of scripts that aren't to be installed, and aren't used
# by the pkgsrc system.  But they all have the non-standard
# "==" in them. (silly linux developers thinking [ bash = sh ].
#
CHECK_PORTABILITY_SKIP=	admin/build/devconfig.sh \
			admin/build/build_package.sh \
			admin/build/prep_dist.sh


INSTALLATION_DIRS=	bin share/psi share/doc/psi
INSTALL_DIRS=		src
INSTALL_TARGET=		install_target install_sharedfiles
INSTALL_MAKE_FLAGS=	INSTALL_ROOT=${DESTDIR}

.include "options.mk"

#
#   LANG_FILES are the translations we're going to install
#
# LANG_FILES= psi_be.qm psi_cs.qm psi_de.qm psi_eo.qm psi_es.qm \
# 	    psi_es_ES.qm psi_fr.qm psi_it.qm psi_ja.qm psi_mk.qm \
# 	    psi_pl.qm psi_pt_BR.qm psi_ru.qm psi_sl.qm psi_sv.qm \
# 	    psi_uk.qm psi_ur_PK.qm psi_vi.qm psi_zh_CN.qm psi_zh_TW.qm

.for f in ${LANG_FILES}
DISTFILES+=	${f}
SITES.${f}=	http://psi-im.org/download/lang/
.endfor

post-install:
	# remove some files that shouldn't be there,
	# install some files where they should be installed
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/psi
	${RM} ${DESTDIR}${PREFIX}/share/psi/README
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/psi
	${RM} ${DESTDIR}${PREFIX}/share/psi/COPYING
	# install the translations
.for f in ${LANG_FILES}
	${INSTALL_DATA} ${WRKDIR}/${f} ${DESTDIR}${PREFIX}/share/psi
.endfor

.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/qca2-qt5/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
