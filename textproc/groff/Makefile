# $NetBSD: Makefile,v 1.97 2022/06/28 11:36:10 wiz Exp $

DISTNAME=	groff-1.22.4
PKGREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=groff/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/groff/groff.html
COMMENT=	GNU roff text processing suite
LICENSE=	gnu-gpl-v3

CHECK_PERMS=		NO
MAKE_JOBS_SAFE=		NO
OVERRIDE_DIRDEPTH=	4

DEPENDS+=		urw-fonts-[0-9]*:../../fonts/urw-fonts

INSTALLATION_DIRS=	share/groff/site-tmac

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		PERLPATH=${PERL5:Q}
TEXINFO_REQD+=		4.8
USE_TOOLS+=		perl sed:run awk:run gmake makeinfo yacc
EXTRACT_USING=		bsdtar
USE_FEATURES=		getopt_long
CONFIGURE_ARGS+=	--with-urw-fonts-dir=${PREFIX}/share/fonts/urw

INFO_FILES=		YES

REPLACE_AWK+=		font/devlj4/generate/special.awk
REPLACE_PERL+=		contrib/*/*.pl
REPLACE_PERL+=		src/roff/grog/grog.pl
REPLACE_PERL+=		src/roff/grog/subs.pl

REPLACE_INTERPRETER+=	sed
REPLACE.sed.old=	.*/sed
REPLACE.sed.new=	${SED}
REPLACE_FILES.sed+=	font/devps/generate/symbol.sed

.include "options.mk"

PLIST_SRC+=		${WRKDIR}/PLIST-local
PLIST_SRC+=		PLIST

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	PAPERSIZE
.if defined(PAPERSIZE)
CONFIGURE_ENV+=	PAGE=${PAPERSIZE:Q}
.endif

post-extract:
	${CP} -p ${FILESDIR}/*.c ${WRKSRC}

# Usually the mdoc.local "volume-operating-system" definition is for
# the operating system name often displayed on top of man pages. And
# "operating-system" is for the default .Os value (operating system
# and version/release) and is usually displayed at bottom of man page.
# XXX Use "pkgsrc" as default .Os value.
post-patch:
	${SED}	-e "s,@@VOLUME_OPERATING_SYSTEM@@,${OPSYS},g"	\
		-e "s,@@OPERATING_SYSTEM@@,pkgsrc,g"	\
		${FILESDIR}/mdoc.local > ${WRKDIR}/mdoc.local

# Groff installs its own man and ms macros as mgan and mgs if the
# configure script thinks replacing the system ones is not safe. Since
# this depends heavily on exactly what the system macros are, each
# vendor OS is likely to be different and possibly differ by version.
#
# It also installs wrappers around the system macros for a variety of
# other traditional macro packages, if those macros don't have an FSF
# copyright.
SYMLINK_FILES=		chem diffmk eqn grn indxbib lookbib neqn nroff pic refer \
			soelim tbl troff
SYMLINK_MANFILES=	chem.1 eqn.1 grn.1 indxbib.1 lookbib.1 neqn.1 nroff.1 \
			pic.1 refer.1 soelim.1 tbl.1 troff.1

INSTALLATION_DIRS=	${PKGGNUDIR}bin ${PKGGNUDIR}${PKGMANDIR}/man1

post-install:
	${INSTALL_DATA} ${WRKDIR}/mdoc.local \
		${DESTDIR}${PREFIX}/share/groff/site-tmac
	${FIND} ${DESTDIR}${PREFIX}/lib/groff/site-tmac -type f -print | \
		${SED} 's;${DESTDIR}${PREFIX}/;;g' > ${WRKDIR}/PLIST-local
	${RUN}set -e; for f in an.tmac m.tmac mm.tmac mmse.tmac		\
	  mse.tmac s.tmac; do						\
	  for p in "" g; do						\
	    line="share/groff/${PKGVERSION_NOREV}/tmac/$$p$$f";		\
	    if [ -e "${DESTDIR}${PREFIX}/$$line" ]; then		\
	      break;							\
	    fi;								\
	  done;								\
	  ${ECHO} "$$line" >> ${WRKDIR}/PLIST-local;			\
	done
.for f in ${SYMLINK_FILES}
	if [ -f ${DESTDIR}${PREFIX}/bin/g${f} ]; then			\
	    ${LN} -sf ${PREFIX}/bin/g${f}				\
		${DESTDIR}${PREFIX}/${PKGGNUDIR}bin/${f};		\
	fi
.endfor
# fixup where necessary and symlink man pages
.for f in ${SYMLINK_MANFILES}
	if [ -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/g${f} ]; then	\
	    ${LN} -sf ${PREFIX}/${PKGMANDIR}/man1/g${f}			\
		${DESTDIR}${PREFIX}/${PKGGNUDIR}${PKGMANDIR}/man1/${f};	\
	elif [ -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${f} ]; then	\
	    ${MV} -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${f}		\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/g${f};		\
	    ${LN} -sf ${PREFIX}/${PKGMANDIR}/man1/g${f}			\
		${DESTDIR}${PREFIX}/${PKGGNUDIR}${PKGMANDIR}/man1/${f};	\
	fi
.endfor

# we only want the charset.alias file, so no buildlinkery for libiconv
#DEPENDS+=	libiconv-[0-9]*:../../converters/libiconv
.include "../../mk/bsd.pkg.mk"
