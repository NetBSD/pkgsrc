# $NetBSD: Makefile,v 1.13 2015/09/06 00:11:12 mef Exp $

DISTNAME=		uhd-3.9.0
CATEGORIES=		ham
MASTER_SITES=           ${MASTER_SITE_GITHUB:=EttusResearch/}
GITHUB_TAG=		release_003_008_005

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://code.ettus.com/redmine/ettus/projects/uhd/wiki
COMMENT=		USRP (Universal Software Radio Peripheral) Hardware Drivers
LICENSE=		gnu-gpl-v2

BUILD_DEPENDS+=		${PYPKGPREFIX}-cheetah-[0-9]*:../../devel/py-cheetah
BUILD_DEPENDS+=		${PYPKGPREFIX}-docutils>=0.12:../../textproc/py-docutils

CMAKE_ARGS+=		-DRST2HTML_EXECUTABLE=${PREFIX}/bin/rst2html-${PYVERSSUFFIX}.py
CMAKE_ARGS+=		-Wno-dev

USE_LANGUAGES=		c c++
USE_TOOLS=		cmake pkg-config
USE_CMAKE=		yes
# extra pax_global_header exists, and to avoid that:
EXTRACT_USING=		gtar
#EXTRACT_ELEMENTS=	uhd-${GITHUB_TAG}

# Please note distribution has many stuff under uhd/, but build itself
# needs under host/ only.  Those uhd/ stuff will be handled post-{patch,install}:
WRKSRC=			${WRKDIR}/uhd-${GITHUB_TAG}/host

# The files with their name uhd-xxxx, are moved down from uhd/xxxx for this process.
REPLACE_PYTHON=	\
	utils/latency/graph.py \
	utils/latency/run_tests.py \
	utils/uhd_images_downloader.py.in \
	utils/usrp2_card_burner.py \
	utils/usrp2_card_burner_gui.py \
	utils/usrp_n2xx_net_burner.py \
	utils/usrp_n2xx_net_burner_gui.py \
	uhd-firmware/fx2/utils/build_eeprom.py \
	uhd-firmware/fx2/utils/edit-gpif-b100.py \
	uhd-firmware/fx2/utils/edit-gpif.py \
	uhd-firmware/fx2/utils/generate_regs.py \

INSTALLATION_DIRS+=	share/uhd
INSTALLATION_DIRS+=	share/uhd/firmware
INSTALLATION_DIRS+=	share/uhd/fpga
INSTALLATION_DIRS+=	share/uhd/images

SUBST_CLASSES+=		man
SUBST_MESSAGE.man=	Convert share/man to man
SUBST_STAGE.man=	pre-configure
SUBST_FILES.man=	docs/CMakeLists.txt
SUBST_SED.man=		-e '/UHD_INSTALL/s,$${PKG_MAN_DIR},${PREFIX}/${PKGMANDIR}/man1,'
# UHD_INSTALL(FILES ${gzfile} DESTINATION ${PKG_MAN_DIR} COMPONENT manpages)

# is it default ? and redundent ?
PLIST_SRC=	${PKGDIR}/PLIST
.include "options.mk"

# Copy (beyond) upper directory files (which should be handled at post-install)
# to receive REPLACE_PYTHON conversion ( otherwise above the range )
post-patch:
	(cd ${WRKDIR}; \
	for i in firmware images ; do \
	  ${MKDIR} ${WRKSRC}/uhd-$$i ;\
	${CP} -r ${WRKDIR}/uhd-${GITHUB_TAG}/$$i/* ${WRKSRC}/uhd-$$i ;\
	done)

# (1) move back the files to original location after REPLACE_PYTHON handled
# (2) suppress warning at intallation, "non executable files get +x bit set".
#
#  Converting ${CP} into ${INTALL_DATA_DIR} and ${INSTALL_DATA} as pkglint
#  flags are NOT easy, sorry for that.
post-install:
	for i in firmware images ; do \
	  ${CP} -r ${WRKSRC}/uhd-$$i/* ${DESTDIR}${PREFIX}/share/uhd/$$i/;\
	  ${FIND} ${DESTDIR}${PREFIX}/share/uhd/$$i -type f -exec \
	          ${CHMOD} -x '{}' \; ;\
		done

.include "../../lang/python/application.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../devel/orc/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
