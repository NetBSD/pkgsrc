# $NetBSD: Makefile,v 1.2 2003/04/10 18:42:29 wiz Exp $
#

DISTNAME=	coreutils-5.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GNU:=coreutils/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	marc@informatik.uni-bremen.de
HOMEPAGE=	http://www.gnu.org/software/coreutils/
COMMENT=	GNU basic file, shell and text manipulation utilities

BUILD_USES_MSGFMT=	YES

CONFLICTS=	sh-utils-* fileutils-*
CONFLICTS+=	textutils-*

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
USE_PERL5=		build

.include "../../mk/bsd.prefs.mk"

.if defined(GNU_PROGRAM_PREFIX)
CONFIGURE_ARGS=		--program-prefix=${GNU_PROGRAM_PREFIX}
# devel/id-utils installs a 'gid' program, so conflict with it if
# GNU_PROGRAM_PREFIX == 'g'
.  if ${GNU_PROGRAM_PREFIX} == "g"
CONFLICTS+=		id-utils-[0-9]*
CONFLICTS+=		gnome-utils-*
.  endif
.endif
PLIST_SUBST+=		GNU_PROGRAM_PREFIX=${GNU_PROGRAM_PREFIX}
BUILD_DEFS+=		GNU_PROGRAM_PREFIX

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
