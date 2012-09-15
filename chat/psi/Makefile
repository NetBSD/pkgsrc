# $NetBSD: Makefile,v 1.68 2012/09/15 10:03:55 obache Exp $

PSI_VERSION=	0.14
DISTNAME=	psi-${PSI_VERSION}
PKGNAME=	${DISTNAME:S/-rc/rc/}
PKGREVISION=	8
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=psi/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	eric@cirr.com
HOMEPAGE=	http://psi-im.org/
COMMENT=	Psi XMPP/Jabber Client
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	qca2-ossl>=2.0.0beta3:../../security/qca2-ossl

DIST_SUBDIR=	${DISTNAME}
DISTFILES=	${DEFAULT_DISTFILES} ${LANG_PACK}

USE_TOOLS+=	gmake unzip
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
HAS_CONFIGURE=	yes

CONFIG_SHELL=	${SH}

CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--qtdir=${QTDIR:Q}
CONFIGURE_ARGS+=	--disable-bundled-qca
CONFIGURE_ARGS+=	--with-zlib-inc=${BUILDLINK_PREFIX.zlib}/include
CONFIGURE_ARGS+=	--with-zlib-lib=${BUILDLINK_PREFIX.zlib}/lib

#
#   LANG_PACK is an archive of all the translations..
#
LANG_PACK=psi-0.14_langpack_2009-12-02.zip
SITES.${LANG_PACK}= http://fs.scs-tsa.de/psi_l10n/

#
#   LANG_FILES are the translations we're going to install
#

LANG_FILES= be/psi_be.qm cs/psi_cs.qm de/psi_de.qm fr/psi_fr.qm \
	    it/psi_it.qm ja/psi_ja.qm pl/psi_pl.qm ru/psi_ru.qm \
	    sl/psi_sl.qm sv/psi_sv.qm pt_BR/psi_pt_BR.qm \
	    ur_PK/psi_ur_PK.qm zh_TW/psi_zh_TW.qm

INSTALLATION_DIRS=	bin share/psi share/doc/psi
INSTALL_DIRS=		src
INSTALL_TARGET=		install_target install_sharedfiles
INSTALL_MAKE_FLAGS=	INSTALL_ROOT=${DESTDIR}

.include "options.mk"

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
.include "../../security/qca2/buildlink3.mk"
BUILDLINK_API_DEPENDS.qt4-libs+=	qt4-libs>=4.4.0
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
