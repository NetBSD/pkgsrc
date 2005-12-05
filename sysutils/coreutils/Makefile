# $NetBSD: Makefile,v 1.29 2005/12/05 20:50:59 rillig Exp $

DISTNAME=	coreutils-5.2.1
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNU:=coreutils/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/coreutils/
COMMENT=	GNU basic file, shell and text manipulation utilities

NOT_FOR_PLATFORM=	NetBSD-2.0[D-H]-*

BUILD_USES_MSGFMT=	YES

CONFLICTS=	fileutils-* linuxls-* sh-utils-* textutils-*

GNU_CONFIGURE=		YES
USE_TOOLS+=		perl
USE_PKGLOCALEDIR=	YES

INFO_FILES=	coreutils.info

TEST_TARGET=		check

SUBST_CLASSES+=		root
SUBST_MESSAGE.root=	"Fixing hardcoded root."
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
CONFLICTS+=		graphviz-[0-9]*
.endif
# print/teTeX-bin and print/teTeX1-bin installs a 'readlink' program, so
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
MESSAGE_SUBST+=	OPSYS=${OPSYS}
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
