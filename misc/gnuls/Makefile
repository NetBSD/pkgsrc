# $NetBSD: Makefile,v 1.10 2004/10/03 00:12:59 tv Exp $
#

DISTNAME=	coreutils-5.2.1
PKGNAME=	${DISTNAME:S/coreutils/gnuls/}
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU:=coreutils/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/coreutils/
COMMENT=	GNU ls utility with color support

CONFLICTS=	coreutils-[0-9]* linuxls-[0-9]*

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_PERL5=		build

PLIST_SUBST+=		GNU_PROGRAM_PREFIX="${GNU_PROGRAM_PREFIX}"
BUILD_DEFS+=		GNU_PROGRAM_PREFIX

INSTALL_DIRS=		bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/dircolors \
		${PREFIX}/bin/${GNU_PROGRAM_PREFIX}dircolors
	${INSTALL_PROGRAM} ${WRKSRC}/src/ls \
		${PREFIX}/bin/${GNU_PROGRAM_PREFIX}ls
	${INSTALL_DATA} ${WRKSRC}/man/dircolors.1 \
		${PREFIX}/man/man1/${GNU_PROGRAM_PREFIX}dircolors.1
	${INSTALL_DATA} ${WRKSRC}/man/ls.1 \
		${PREFIX}/man/man1/${GNU_PROGRAM_PREFIX}ls.1

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
