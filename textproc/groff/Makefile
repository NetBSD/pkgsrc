# $NetBSD: Makefile,v 1.48 2008/11/10 17:21:38 wiz Exp $
#

DISTNAME=	groff-1.19.2
PKGREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=groff/}

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/groff/groff.html
COMMENT=	GNU roff text processing suite

CHECK_PERMS=		NO

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		PERLPATH=${PERL5:Q}
USE_TOOLS+=		perl:run sed:run awk:run
USE_FEATURES=		getopt_long

INFO_FILES=		YES

REPLACE_INTERPRETER+=	sed
REPLACE.sed.old=	.*/sed
REPLACE.sed.new=	${SED}
REPLACE_FILES.sed+=	font/devps/generate/symbol.sed

.include "options.mk"

PLIST_SRC+=		${WRKDIR}/PLIST-local
PLIST_SRC+=		PLIST

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
PLIST_SUBST+=	GNU_PREFIX="g"
.else
PLIST_SUBST+=	GNU_PREFIX=""
.endif

.if ${OPSYS} == "SunOS" || ${OPSYS} == "HPUX"
PLIST_SUBST+=	GNU_PREFIX_TMAC="g"
.else
PLIST_SUBST+=	GNU_PREFIX_TMAC=""
.endif

.if ${OPSYS} == "SunOS" || ${OPSYS} == "HPUX" || ${OPSYS} == "OSF1"
PLIST_SUBST+=	GNU_PREFIX_AN_TMAC="g"
.else
PLIST_SUBST+=	GNU_PREFIX_AN_TMAC=""
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
		${PREFIX}/share/groff/site-tmac
	${FIND} ${PREFIX}/lib/groff/site-tmac -type f -print | \
		${SED} 's;${PREFIX}/;;g' > ${WRKDIR}/PLIST-local

.include "../../mk/bsd.pkg.mk"
