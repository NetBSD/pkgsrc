# $NetBSD: Makefile,v 1.20 2004/04/25 03:33:12 snj Exp $

DISTNAME=	coreutils-5.2.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNU:=coreutils/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/coreutils/
COMMENT=	GNU basic file, shell and text manipulation utilities

BUILD_USES_MSGFMT=	YES

CONFLICTS=	fileutils-* linuxls-* sh-utils-* textutils-*

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_PERL5=		build

INFO_FILES=	coreutils.info

TEST_TARGET=		check

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS=		--program-prefix=${GNU_PROGRAM_PREFIX}
# if GNU_PROGRAM_PREFIX == 'g'
# devel/id-utils installs a 'gid' program, so conflict with it
# databases/geneweb a 'gwc' program, so conflict with it
# graphics/graphviz installs a 'gpr' program, so conflict with it
.if ${GNU_PROGRAM_PREFIX} == "g"
CONFLICTS+=		id-utils-[0-9]* gnome-utils<1.4.1.2nb2
CONFLICTS+=		geneweb-[0-9]*
CONFLICTS+=		graphviz-[0-9]*
.endif
# print/teTeX*-bin installs a 'readlink' program, so conflict with it if
# GNU_PROGRAM_PREFIX == ''
.if ${GNU_PROGRAM_PREFIX} == ""
CONFLICTS+=		teTeX-bin-[0-9]*
.endif

PLIST_SUBST+=		GNU_PROGRAM_PREFIX=${GNU_PROGRAM_PREFIX}
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
