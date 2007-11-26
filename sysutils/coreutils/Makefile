# $NetBSD: Makefile,v 1.42 2007/11/26 15:40:45 tron Exp $

DISTNAME=	coreutils-6.9
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNU:=coreutils/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/coreutils/
COMMENT=	GNU basic file, shell and text manipulation utilities

NOT_FOR_PLATFORM=	NetBSD-2.0[D-H]-*

CONFLICTS=	fileutils-[0-9]* linuxls-[0-9]* sh-utils-[0-9]* textutils-[0-9]*

CFLAGS+=		-g
LDFLAGS+=		-g
GNU_CONFIGURE=		YES
USE_TOOLS+=		msgfmt msgmerge perl xgettext
USE_PKGLOCALEDIR=	YES

INFO_FILES=		# PLIST

TEST_TARGET=		check

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Interix"
CONFIGURE_ENV+=		ac_list_mounted_fs=found
.endif

.if !empty(MACHINE_PLATFORM:MDarwin-[9].*-*)
CONFIGURE_ENV+=		 ac_cv_header_sys_acl_h=no jm_cv_func_svid_putenv=yes
.endif

# Exclude programs from PLIST which aren't built on a platform.
.if ${OPSYS} == "Interix"
PLIST_SUBST+=		COREUTILS_HAVE_HOSTID="@comment "
.else
PLIST_SUBST+=		COREUTILS_HAVE_HOSTID=""
.endif

# XXX - this hack is bound to cause fallout on some platform at some point.
# How can we determine the API version of the builtin gettext?
.if ${OPSYS} != "Linux"
CONFIGURE_ENV+=		gt_cv_func_gnugettext3_libintl=yes
.endif
CONFIGURE_ENV+=		MKDIR_P=${MKDIR:Q}

CONFIGURE_ARGS+=	--program-prefix=${GNU_PROGRAM_PREFIX:Q}
# if GNU_PROGRAM_PREFIX == 'g'
# devel/id-utils installs a 'gid' program, so conflict with it
# databases/geneweb a 'gwc' program, so conflict with it
# graphics/graphviz installs a 'gpr' program, so conflict with it
.if ${GNU_PROGRAM_PREFIX} == "g"
CONFLICTS+=		id-utils-[0-9]* gnome-utils<1.4.1.2nb2
CONFLICTS+=		geneweb-[0-9]*
CONFLICTS+=		graphviz<1.12
.endif
# print/teTeX-bin installed a 'readlink' program, so
# conflict with it if GNU_PROGRAM_PREFIX == '' (no problem in teTeX3-bin)
.if ${GNU_PROGRAM_PREFIX} == ""
CONFLICTS+=		teTeX-bin<3
.endif

PLIST_SUBST+=		GNU_PROGRAM_PREFIX=${GNU_PROGRAM_PREFIX:Q}
BUILD_DEFS+=		GNU_PROGRAM_PREFIX

.if ${OPSYS} == "NetBSD" ||  ${OPSYS} == "FreeBSD" || \
  ${OPSYS} == "OpenBSD"
MAKE_FLAGS+=	setuid_root_mode=a=rx
MESSAGE_SRC=	${.CURDIR}/MESSAGE.gsu
MESSAGE_SUBST+=	OPSYS=${OPSYS:Q}
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
