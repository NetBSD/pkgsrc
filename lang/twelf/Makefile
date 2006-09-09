# $NetBSD: Makefile,v 1.15 2006/09/09 02:43:09 obache Exp $
#

DISTNAME=	twelf-1-4
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	4
CATEGORIES=	lang
MASTER_SITES=	http://www.cs.cmu.edu/~twelf/dist/

MAINTAINER=	richards+netbsd@CS.Princeton.EDU
HOMEPAGE=	http://www.cs.cmu.edu/~twelf/
COMMENT=	Meta-language for proving properties of languages and logics

DEPENDS+=	smlnj>=110.38:../../lang/smlnj

LICENSE=	generic-nonlicense
RESTRICTED=	License terms not specified; assume no redistribution rights
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

WRKSRC=		${WRKDIR}/twelf
MAKE_FILE=	smlnj/Makefile
MAKEFLAGS+=	sml=${PREFIX:Q}/bin/sml
BUILD_TARGET=	twelf-server twelf-sml

INFO_FILES=		# PLIST

TWELF_LIBDIR=		${PREFIX}/lib/twelf
TWELF_EMACSDIR=		${EMACS_LISPPREFIX}/twelf
TWELF_DOCDIR=		${PREFIX}/share/doc/twelf
TWELF_HTMLDOCDIR=	${PREFIX}/share/doc/html/twelf
TWELF_EXAMPLEDIR=	${PREFIX}/share/examples/twelf

.include "../../lang/smlnj/Makefile.common"

INSTALLATION_DIRS+=	bin ${PKGINFODIR}				\
			${TWELF_LIBDIR} ${TWELF_EMACSDIR}		\
			${TWELF_DOCDIR} ${TWELF_HTMLDIR}		\
			${TWELF_EXAMPLEDIR}

post-extract:
	${CHMOD} -R +r ${WRKSRC}

post-patch:
.for f in bin/.mkexec emacs/twelf-init.el
	${CP} ${WRKSRC}/${f} ${WRKSRC}/${f}.orig
	${SED} -e 's:@TWELF_LIBDIR@:'${TWELF_LIBDIR}':g'	\
		${WRKSRC}/${f}.orig > ${WRKSRC}/${f}
.endfor

post-build:
	find ${WRKSRC} -name "*.orig" | xargs rm

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pam bin ${TWELF_LIBDIR}
	${LN} -sf ${TWELF_LIBDIR}/bin/* ${PREFIX}/bin

	cd ${WRKSRC}/emacs && ${PAX} -rw -pam * ${TWELF_EMACSDIR}
	${LN} -sf ${TWELF_EMACSDIR} ${TWELF_LIBDIR}/emacs

	cd ${WRKSRC}/doc; for t in dvi pdf ps; do			\
		${INSTALL_DATA} $${t}/twelf.$${t} ${TWELF_DOCDIR};	\
	done
	${LN} -sf ${TWELF_DOCDIR} ${TWELF_LIBDIR}/doc

	cd ${WRKSRC}/doc/info; for f in *.info *.info-[0-9]*; do	\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${PREFIX}/${PKGINFODIR};		\
	done

	cd ${WRKSRC}/doc/html && ${PAX} -rw -pam * ${TWELF_HTMLDOCDIR}

	cd ${WRKSRC}/examples && ${PAX} -rw -pam * ${TWELF_EXAMPLEDIR}
	${LN} -sf ${TWELF_EXAMPLEDIR} ${TWELF_LIBDIR}/examples

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
