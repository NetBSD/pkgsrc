# $NetBSD: Makefile,v 1.14 2004/02/11 23:12:50 jmmv Exp $

DISTNAME=	coreutils-5.0
PKGREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNU:=coreutils/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/coreutils/
COMMENT=	GNU basic file, shell and text manipulation utilities

BUILD_USES_MSGFMT=	YES

CONFLICTS=	fileutils-* linuxls-* sh-utils-* textutils-*

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_PERL5=		build

INFO_FILES=	coreutils.info

TEST_TARGET=		check

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS=		--program-prefix=${GNU_PROGRAM_PREFIX}
# devel/id-utils installs a 'gid' program, so conflict with it if
# GNU_PROGRAM_PREFIX == 'g'
.if ${GNU_PROGRAM_PREFIX} == "g"
CONFLICTS+=		id-utils-[0-9]* gnome-utils<1.4.1.2nb2
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

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
