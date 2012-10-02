# $NetBSD: Makefile,v 1.22 2012/10/02 20:11:56 asau Exp $
#

DISTNAME=	twelf-1-4
PKGNAME=	${EMACS_PKGNAME_PREFIX}twelf-1.4
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.cs.cmu.edu/~twelf/dist/

MAINTAINER=	richards+netbsd@CS.Princeton.EDU
HOMEPAGE=	http://www.cs.cmu.edu/~twelf/
COMMENT=	Meta-language for proving properties of languages and logics
LICENSE=	generic-nonlicense

RESTRICTED=	License terms not specified; assume no redistribution rights
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

DEPENDS+=	smlnj>=110.38:../../lang/smlnj

USE_TOOLS+=	pax

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
	cd ${WRKSRC} && pax -rw -pam bin ${DESTDIR}${TWELF_LIBDIR}
	${LN} -sf ${DESTDIR}${TWELF_LIBDIR}/bin/* ${DESTDIR}${PREFIX}/bin

	cd ${WRKSRC}/emacs && pax -rw -pam * ${DESTDIR}${TWELF_EMACSDIR}
	${LN} -sf ${DESTDIR}${TWELF_EMACSDIR} ${DESTDIR}${TWELF_LIBDIR}/emacs

	cd ${WRKSRC}/doc; for t in dvi pdf ps; do			\
		${INSTALL_DATA} $${t}/twelf.$${t} ${DESTDIR}${TWELF_DOCDIR};	\
	done
	${LN} -sf ${DESTDIR}${TWELF_DOCDIR} ${DESTDIR}${TWELF_LIBDIR}/doc

	cd ${WRKSRC}/doc/info; for f in *.info *.info-[0-9]*; do	\
		${TEST} ! -f "$$f" ||					\
		${INSTALL_DATA} "$$f" ${DESTDIR}${PREFIX}/${PKGINFODIR};		\
	done

	cd ${WRKSRC}/doc/html && pax -rw -pam * ${DESTDIR}${TWELF_HTMLDOCDIR}

	cd ${WRKSRC}/examples && pax -rw -pam * ${DESTDIR}${TWELF_EXAMPLEDIR}
	${LN} -sf ${DESTDIR}${TWELF_EXAMPLEDIR} ${DESTDIR}${TWELF_LIBDIR}/examples

.include "../../editors/emacs/modules.mk"
.include "../../mk/bsd.pkg.mk"
