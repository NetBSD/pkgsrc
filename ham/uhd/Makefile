# $NetBSD: Makefile,v 1.10 2015/04/17 15:53:09 adam Exp $

DISTNAME=		uhd-release_003_007_002
PKGNAME=		uhd-3.7.2
PKGREVISION=		2
CATEGORIES=		ham
MASTER_SITES=		-https://github.com/EttusResearch/uhd/archive/${DISTNAME:S/uhd-//}${EXTRACT_SUFX}
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://code.ettus.com/redmine/ettus/projects/uhd/wiki
COMMENT=		USRP (Universal Software Radio Peripheral) Hardware Drivers
LICENSE=		gnu-gpl-v2

BUILD_DEPENDS+=		${PYPKGPREFIX}-cheetah-[0-9]*:../../devel/py-cheetah
BUILD_DEPENDS+=		${PYPKGPREFIX}-docutils>=0.12:../../textproc/py-docutils

CMAKE_ARGS+=		-DRST2HTML_EXECUTABLE=${PREFIX}/bin/rst2html-${PYVERSSUFFIX}.py

USE_LANGUAGES=		c c++
USE_TOOLS=		cmake pkg-config
USE_CMAKE=		yes

# Please note distribution has many stuff under uhd/, but build itself
# needs under host/ only.  Those uhd/ stuff will be handled post-{patch,install}:
WRKSRC=			${WRKDIR}/${DISTNAME}/host

# The files with their name uhd-xxxx, are moved down from uhd/xxxx for this process.
REPLACE_PYTHON=	\
	utils/uhd_images_downloader.py.in \
	utils/usrp2_card_burner.py \
	utils/usrp2_card_burner_gui.py \
	utils/usrp_n2xx_net_burner.py \
	utils/usrp_n2xx_net_burner_gui.py \
	uhd-firmware/fx2/utils/build_eeprom.py \
	uhd-firmware/fx2/utils/edit-gpif-b100.py \
	uhd-firmware/fx2/utils/edit-gpif.py \
	uhd-firmware/fx2/utils/generate_regs.py \
        uhd-firmware/x300/bin_to_coe.py \
	uhd-firmware/zpu/bin/bin_to_mif.py \
	uhd-firmware/zpu/bin/bin_to_ram_macro_init.py \
	uhd-firmware/zpu/bin/divisors.py \
	uhd-firmware/zpu/bin/elf_to_sbf \
	uhd-firmware/zpu/bin/serial_loader \
	uhd-firmware/zpu/bin/uart_ihex_flash_loader.py \
	uhd-firmware/zpu/bin/uart_ihex_ram_loader.py \
	uhd-fpga/usrp1/gen_makefile_extra.py \
	uhd-fpga/usrp1/sdr_lib/gen_cordic_consts.py \
	uhd-fpga/usrp1/tb/makesine.pl \
	uhd-fpga/usrp1/toplevel/mrfm/mrfm.py \
	uhd-fpga/usrp1/toplevel/mrfm/mrfm_fft.py \
	uhd-fpga/usrp2/sdr_lib/gen_cordic_consts.py \
	uhd-fpga/usrp2/top/extract_usage.py \
	uhd-fpga/usrp2/top/python/check_inout.py \
	uhd-fpga/usrp2/top/python/check_timing.py \
	uhd-fpga/usrp3/top/python/bit_to_zynq_bin.py \
	uhd-fpga/usrp3/top/python/check_inout.py \
	uhd-fpga/usrp3/top/python/check_timing.py \
        uhd-fpga/usrp3/lib/io_port2/create-lvbitx.py

REPLACE_PERL=	uhd-fpga/usrp1/tb/makesine.pl

REPLACE_BASH=	\
	uhd-fpga/usrp2/top/impactor.sh \
	uhd-fpga/usrp3/top/impactor.sh \
        uhd-fpga/usrp3/top/python/batch-build

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
	for i in firmware fpga images ; do \
	  ${MKDIR} ${WRKSRC}/uhd-$$i ;\
	${CP} -r ${WRKDIR}/${DISTNAME}/$$i/* ${WRKSRC}/uhd-$$i ;\
	done)

# (1) move back the files to original location after REPLACE_PYTHON handled
# (2) suppress warning at intallation, "non executable files get +x bit set".
#
#  Converting ${CP} into ${INTALL_DATA_DIR} and ${INSTALL_DATA} as pkglint
#  flags are NOT easy, sorry for that.
post-install:
	for i in firmware fpga images ; do \
	  ${CP} -r ${WRKSRC}/uhd-$$i/* ${DESTDIR}${PREFIX}/share/uhd/$$i/;\
	  ${FIND} ${DESTDIR}${PREFIX}/share/uhd/$$i -type f -exec \
	          ${CHMOD} -x '{}' \; ;\
		done

.include "../../lang/python/application.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../devel/orc/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
