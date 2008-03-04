# $NetBSD: Makefile,v 1.19 2008/03/04 19:21:11 jlam Exp $
#

DISTNAME=	coreutils-6.9
PKGNAME=	${DISTNAME:S/coreutils/gnuls/}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU:=coreutils/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/coreutils/
COMMENT=	GNU ls utility with color support

CONFLICTS=	coreutils-[0-9]* linuxls-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES

PLIST_SUBST+=		GNU_PROGRAM_PREFIX=${GNU_PROGRAM_PREFIX:Q}
BUILD_DEFS+=		GNU_PROGRAM_PREFIX

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Interix"
CONFIGURE_ENV+=		ac_list_mounted_fs=found
.endif

.if ${OPSYS} != "Linux"
CONFIGURE_ENV+=		gt_cv_func_gnugettext3_libintl=yes
.endif
CONFIGURE_ENV+=		MKDIR_P=${MKDIR:Q}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/dircolors \
		${DESTDIR}${PREFIX}/bin/${GNU_PROGRAM_PREFIX}dircolors
	${INSTALL_PROGRAM} ${WRKSRC}/src/ls \
		${DESTDIR}${PREFIX}/bin/${GNU_PROGRAM_PREFIX}ls
	${INSTALL_DATA} ${WRKSRC}/man/dircolors.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${GNU_PROGRAM_PREFIX}dircolors.1
	${INSTALL_DATA} ${WRKSRC}/man/ls.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${GNU_PROGRAM_PREFIX}ls.1

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
