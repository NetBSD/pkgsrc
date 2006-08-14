# $NetBSD: Makefile,v 1.36 2006/08/14 08:39:52 wiz Exp $

DISTNAME=	coreutils-5.2.1
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNU:=coreutils/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/coreutils/
COMMENT=	GNU basic file, shell and text manipulation utilities

NOT_FOR_PLATFORM=	NetBSD-2.0[D-H]-*

CONFLICTS=	fileutils-[0-9]* linuxls-[0-9]* sh-utils-[0-9]* textutils-[0-9]*

GNU_CONFIGURE=		YES
USE_TOOLS+=		msgfmt perl
USE_PKGLOCALEDIR=	YES

INFO_FILES=		# PLIST

TEST_TARGET=		check

SUBST_CLASSES+=		root
SUBST_MESSAGE.root=	Fixing hardcoded root.
SUBST_STAGE.root=	post-patch
SUBST_FILES.root=	src/Makefile.in
SUBST_SED.root=		-e 's, root , ${ROOT_USER} ,g'

.include "../../mk/bsd.prefs.mk"

# Exclude programs from PLIST which aren't built on a platform.
.if ${OPSYS} == "Interix"
PLIST_SUBST+=		COREUTILS_HAVE_HOSTID="@comment "
.else
PLIST_SUBST+=		COREUTILS_HAVE_HOSTID=""
.endif

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
MESSAGE_SRC=    ${.CURDIR}/MESSAGE.gsu
MESSAGE_SUBST+=	OPSYS=${OPSYS:Q}
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
