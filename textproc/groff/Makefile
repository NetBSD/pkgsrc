# $NetBSD: Makefile,v 1.53 2009/10/21 16:51:46 tnn Exp $
#

DISTNAME=	groff-1.20.1
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=groff/}

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/groff/groff.html
COMMENT=	GNU roff text processing suite

CHECK_PERMS=		NO
MAKE_JOBS_SAFE=		NO

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	share/groff/site-tmac

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		PERLPATH=${PERL5:Q}
USE_TOOLS+=		perl:run sed:run awk:run
USE_FEATURES=		getopt_long

INFO_FILES=		YES

REPLACE_AWK+=		font/devlj4/generate/special.awk

REPLACE_INTERPRETER+=	sed
REPLACE.sed.old=	.*/sed
REPLACE.sed.new=	${SED}
REPLACE_FILES.sed+=	font/devps/generate/symbol.sed

.include "options.mk"

PLIST_SRC+=		${WRKDIR}/PLIST-local
PLIST_SRC+=		PLIST

.include "../../mk/bsd.prefs.mk"

#
# Groff installs its own man and ms macros as mgan and mgs if the
# configure script thinks replacing the system ones is not safe. Since
# this depends heavily on exactly what the system macros are, each
# vendor OS is likely to be different and possibly differ by version.
#
# It also installs wrappers around the system macros for a variety of
# other traditional macro packages, if those macros don't have an FSF
# copyright.
#
# It also defaults to installing some of its own tools with a 'g'
# prefix on some platforms.
#

.if ${OPSYS} == "HPUX"
PLIST_SUBST+=	GNU_PREFIX=""
PLIST_SUBST+=	GNU_PREFIX_TMAC_WRAPPER="g"
PLIST_SUBST+=	GNU_PREFIX_AN_TMAC="g"
PLIST_SUBST+=	GNU_PREFIX_S_TMAC="g"

.elif ${OPSYS} == "OSF1"
PLIST_SUBST+=	GNU_PREFIX=""
PLIST_SUBST+=	GNU_PREFIX_TMAC_WRAPPER="g"
PLIST_SUBST+=	GNU_PREFIX_AN_TMAC="g"
PLIST_SUBST+=	GNU_PREFIX_S_TMAC="g"

.elif ${OPSYS} == "SunOS"
# According to PR 35295, on (at least) Solaris 10 for x86 you get
# an.tmac and not gan.tmac. If this turns out not to be true for
# earlier/other Solaris revs we'll need more conditionals in here.
PLIST_SUBST+=	GNU_PREFIX="g"
PLIST_SUBST+=	GNU_PREFIX_TMAC_WRAPPER="g"
PLIST_SUBST+=	GNU_PREFIX_AN_TMAC=""
PLIST_SUBST+=	GNU_PREFIX_S_TMAC="g"

.else
PLIST_SUBST+=	GNU_PREFIX=""
PLIST_SUBST+=	GNU_PREFIX_TMAC_WRAPPER=""
PLIST_SUBST+=	GNU_PREFIX_AN_TMAC=""
PLIST_SUBST+=	GNU_PREFIX_S_TMAC=""
.endif


BUILD_DEFS+=	PAPERSIZE
.if defined(PAPERSIZE)
CONFIGURE_ENV+=	PAGE=${PAPERSIZE:Q}
.endif

# Usually the mdoc.local "volume-operating-system" definition is for
# the operating system name often displayed on top of man pages. And
# "operating-system" is for the default .Os value (operating system
# and version/release) and is usually displayed at bottom of man page.
# XXX Use "pkgsrc" as default .Os value.
post-patch:
	${SED}	-e "s,@@VOLUME_OPERATING_SYSTEM@@,${OPSYS},g"	\
		-e "s,@@OPERATING_SYSTEM@@,pkgsrc,g"	\
		${FILESDIR}/mdoc.local > ${WRKDIR}/mdoc.local

post-install:
	${INSTALL_DATA} ${WRKDIR}/mdoc.local \
		${DESTDIR}${PREFIX}/share/groff/site-tmac
	${FIND} ${DESTDIR}${PREFIX}/lib/groff/site-tmac -type f -print | \
		${SED} 's;${DESTDIR}${PREFIX}/;;g' > ${WRKDIR}/PLIST-local

# we only want the charset.alias file, so no buildlinkery for libiconv
DEPENDS+=	libiconv-[0-9]*:../../converters/libiconv
.include "../../mk/bsd.pkg.mk"
