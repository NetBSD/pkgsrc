# $NetBSD: Makefile,v 1.5 2014/02/19 09:44:56 jperkin Exp $
#

DISTNAME=		grub-2.00
PKGNAME=		grub2-2.00
PKGREVISION=		2
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.gnu.org/gnu/grub/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=		gsutre@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/grub/
COMMENT=		GRand Unified Bootloader, version 2
LICENSE=		gnu-gpl-v3

CONFLICTS=		grub-[0-9]*

ONLY_FOR_PLATFORM=	*-*-i386 *-*-x86_64

USE_TOOLS+=		gmake flex bison gettext:run

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--disable-efiemu
CONFIGURE_ARGS+=	--disable-grub-emu-usb
CONFIGURE_ARGS+=	--disable-grub-emu-sdl
CONFIGURE_ARGS+=	--disable-grub-emu-pci
INFO_FILES=		yes
USE_PKGLOCALEDIR=	yes

.include "../../mk/bsd.prefs.mk"

#
# Build requirements, taken from the INSTALL file in GRUB's distribution:
#
# - GCC >= 4.1.3	(in fact >= 4.4 is required for a successful build)
# - Flex >= 2.5.35
# - gettext >= 0.17	(the need for >= 0.17 seems to only concern msgfmt)
#
# Additionnaly, help2man is required to generate the manual pages.
#
GCC_REQD+=		4.4
FLEX_REQD=		2.5.35
BUILD_DEPENDS+=		help2man>=1.36:../../converters/help2man

# XXX Force use of pkgsrc's flex on NetBSD to prevent build failure.
.if ${OPSYS} == "NetBSD"
FLEX_REQD=		9
.endif

#
# The configure script sets the variables `target_cpu' and `platform', which
# are used for the location of the library directory.  The following mimics
# the configure script's behavior for i386 and x86_64.
#
GRUB_TARGET_CPU=	${MACHINE_ARCH}
.if ${LOWER_VENDOR} == "apple"
GRUB_PLATFORM=		efi
.else
GRUB_PLATFORM=		pc
.endif
.if ${GRUB_TARGET_CPU} == "x86_64" && ${GRUB_PLATFORM} == "pc"
GRUB_TARGET_CPU=	i386
.endif
PLIST_SUBST+=		GRUB_TARGET_CPU=${GRUB_TARGET_CPU}
PLIST_SUBST+=		GRUB_PLATFORM=${GRUB_PLATFORM}

#
# Unset ABI to prevent pkgsrc's gcc wrapper from messing with -m flags.
#
.if defined(ABI) && !empty(ABI)
ABI=
.endif

#
# Configuration files.
#
PKG_SYSCONFSUBDIR=	grub
EGDIR=			${PREFIX}/share/examples/grub
INSTALL_MAKE_FLAGS+=	grubconfdir=${EGDIR}
INSTALL_MAKE_FLAGS+=	bashcompletiondir=${EGDIR}
INSTALL_MAKE_FLAGS+=	bash_completion_script=grub-bash-completion.sh

EGFILES=		00_header 05_pkgsrc_theme 30_os-prober 40_custom 41_custom
.if ${OPSYS} == "FreeBSD"
EGFILES+=		10_kfreebsd
.elif ${OPSYS} == "Linux"
EGFILES+=		10_linux
.elif ${OPSYS} == "NetBSD"
EGFILES+=		10_netbsd
.endif
.for file in ${EGFILES}
CONF_FILES_PERMS+=	${EGDIR}/${file} ${PKG_SYSCONFDIR}/${file} ${ROOT_USER} ${ROOT_GROUP} 0755
.endfor
CONF_FILES+=		${EGDIR}/README ${PKG_SYSCONFDIR}/README
CONF_FILES+=		${EGDIR}/default.conf.sample ${PKG_SYSCONFDIR}/default.conf

post-install: do-install-custom-config

.PHONY: do-install-custom-config
do-install-custom-config:
	${INSTALL_DATA} ${FILESDIR}/default.conf ${DESTDIR}${EGDIR}/default.conf.sample
	${INSTALL_SCRIPT} ${FILESDIR}/05_pkgsrc_theme ${DESTDIR}${EGDIR}/05_pkgsrc_theme

#
# Force installation of all OS configuration scripts in ${EGDIR}.
#
SUBST_CLASSES+=			fix-os-conf
SUBST_STAGE.fix-os-conf=	post-patch
SUBST_MESSAGE.fix-os-conf=	Fixing installation of OS configuration scripts.
SUBST_FILES.fix-os-conf=	Makefile.in
SUBST_SED.fix-os-conf=		-e 's,^@COND_HOST_[A-Z]*_TRUE@,,g'

#
# Adjust the configuration paths in scripts.
#
SUBST_CLASSES+=			fix-paths-1
SUBST_STAGE.fix-paths-1=	post-patch
SUBST_MESSAGE.fix-paths-1=	Fixing configuration paths in scripts.
SUBST_FILES.fix-paths-1=	util/grub-install.in util/grub-mkconfig.in
SUBST_SED.fix-paths-1=		-e 's,\(\$${sysconfdir}"\{0\,1\}\)/grub.d,\1,g'
SUBST_SED.fix-paths-1+=		-e 's,\(\$${sysconfdir}"\{0\,1\}\)/default/grub,\1/default.conf,g'

#
# Adjust the search paths for DejaVu fonts in configure.
#
SUBST_CLASSES+=			fix-dejavu
SUBST_STAGE.fix-dejavu=		pre-configure
SUBST_MESSAGE.fix-dejavu=	Fixing dejavu search paths in configure.
SUBST_FILES.fix-dejavu=		configure
SUBST_SED.fix-dejavu=		-e 's, \(/usr/share/fonts/dejavu\);, \1 ${PREFIX}/lib/X11/fonts/TTF;,g'

#
# Do not use `\t' with sed, as it's not portable.
#
SUBST_CLASSES+=			fix-sed-tabs
SUBST_STAGE.fix-sed-tabs=	post-patch
SUBST_MESSAGE.fix-sed-tabs=	Fixing tabulations for sed in scripts.
SUBST_FILES.fix-sed-tabs=	util/grub.d/*.in
SUBST_SED.fix-sed-tabs=		-e 's,\\t,	,g'

#
# Remove executable bit from non-executable files.
#
post-install:
	${CHMOD} a-x ${DESTDIR}${PREFIX}/lib/grub/${GRUB_TARGET_CPU}-${GRUB_PLATFORM}/gdb_grub
	${CHMOD} a-x ${DESTDIR}${PREFIX}/lib/grub/${GRUB_TARGET_CPU}-${GRUB_PLATFORM}/gmodule.pl

#
# Includes.
#
.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
