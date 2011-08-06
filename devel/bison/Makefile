# $NetBSD: Makefile,v 1.78 2011/08/06 17:15:42 wiz Exp $

DISTNAME=		bison-2.5
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=bison/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/bison/bison.html
COMMENT=		GNU yacc(1) replacement
LICENSE=		gnu-gpl-v3

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		grep gm4:run msgfmt
INFO_FILES=		yes

CONFIGURE_ENV+=		gt_cv_func_gnugettext1_libintl=yes \
			ac_cv_prog_M4=${TOOLS_PATH.gm4}

TEST_TARGET=		check

# Avoid rebuilding manpage
pre-build:
	${TOUCH} ${WRKSRC}/doc/bison.1

# "bison" wants a recent version of "gettext" which at least some
# NetBSD versions don't provide. Figure out whether it will install
# the locale files or not.
PLIST_SRC=	${WRKDIR}/PLIST

post-configure:
	if grep -q '^POSUB = po$$' ${WRKSRC}/Makefile; then		\
	  ${CP} ${PKGDIR}/PLIST ${PLIST_SRC};				\
	else								\
	  ${GREP} -v '^share/locale/' ${PKGDIR}/PLIST >${PLIST_SRC};	\
	fi

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
