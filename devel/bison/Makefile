# $NetBSD: Makefile,v 1.102 2016/02/25 12:12:47 jperkin Exp $

DISTNAME=	bison-3.0.4
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=bison/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/bison/bison.html
COMMENT=	GNU yacc(1) replacement
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		grep gm4:run msgfmt flex perl:build
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-yacc
CONFIGURE_ENV+=		gt_cv_func_gnugettext1_libintl=yes
CONFIGURE_ENV+=		ac_cv_prog_M4=${TOOLS_PATH.gm4}

INFO_FILES=		yes
TEST_TARGET=		check
REPLACE_PERL+=		examples/extexi
REPLACE_SH+=		examples/test examples/*/*.test

CONFIGURE_ARGS.Cygwin+=	ac_cv_func___fpending=yes

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
