# $NetBSD: Makefile,v 1.9 2005/06/16 06:58:01 jlam Exp $
#

DISTNAME=	twelf-1-4
PKGNAME=	twelf-1.4
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.cs.cmu.edu/~twelf/dist/

MAINTAINER=	richards+netbsd@CS.Princeton.EDU
HOMEPAGE=	http://www.cs.cmu.edu/~twelf/
COMMENT=	Meta-language for proving properties of languages and logics

DEPENDS+=	smlnj>=110.38:../../lang/smlnj

RESTRICTED=	License terms not specified; assume no redistribution rights
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

WRKSRC=		${WRKDIR}/twelf
MAKEFILE=	smlnj/Makefile
MAKEFLAGS+=	sml=${PREFIX:Q}/bin/sml
BUILD_TARGET=	twelf-server twelf-sml

INFO_FILES=		twelf.info

TWELF_LIBDIR=		${PREFIX}/lib/twelf
TWELF_EMACSDIR=		${EMACS_LISPPREFIX}/twelf
TWELF_DOCDIR=		${PREFIX}/share/doc/twelf
TWELF_HTMLDOCDIR=	${PREFIX}/share/doc/html/twelf
TWELF_EXAMPLEDIR=	${PREFIX}/share/examples/twelf

.include "../../lang/smlnj/Makefile.common"

INSTALLATION_DIRS+=	bin

post-extract:
	${CHMOD} -R +r ${WRKSRC}

post-patch:
.for f in bin/.mkexec emacs/twelf-init.el
	${CP} ${WRKSRC}/${f} ${WRKSRC}/${f}.orig
	${SED} -e 's:@TWELF_LIBDIR@:'${TWELF_LIBDIR}':g'	\
		${WRKSRC}/${f}.orig > ${WRKSRC}/${f}
.endfor

pre-install:
	${RM} -f ${WRKSRC}/bin/.mkexec.orig ${WRKSRC}/doc/info/*.orig

do-install:
	${INSTALL_DATA_DIR} ${TWELF_LIBDIR}
	cd ${WRKSRC} && ${PAX} -rw -pam bin ${TWELF_LIBDIR}
	${LN} -sf ${TWELF_LIBDIR}/bin/* ${PREFIX}/bin

	${INSTALL_DATA_DIR} ${TWELF_EMACSDIR}
	cd ${WRKSRC}/emacs && ${PAX} -rw -pam * ${TWELF_EMACSDIR}
	${LN} -sf ${TWELF_EMACSDIR} ${TWELF_LIBDIR}/emacs

	${INSTALL_DATA_DIR} ${TWELF_DOCDIR}
	cd ${WRKSRC}/doc && 						\
	for t in dvi pdf ps; do						\
	   ${INSTALL_DATA} $${t}/twelf.$${t} ${TWELF_DOCDIR};		\
	done
	${LN} -sf ${TWELF_DOCDIR} ${TWELF_LIBDIR}/doc

	cd ${WRKSRC}/doc/info && ${PAX} -rw -pam * ${PREFIX}/info

	${INSTALL_DATA_DIR} ${TWELF_HTMLDOCDIR}
	cd ${WRKSRC}/doc/html && ${PAX} -rw -pam * ${TWELF_HTMLDOCDIR}

	${INSTALL_DATA_DIR} ${TWELF_EXAMPLEDIR}
	cd ${WRKSRC}/examples && ${PAX} -rw -pam * ${TWELF_EXAMPLEDIR}
	${LN} -sf ${TWELF_EXAMPLEDIR} ${TWELF_LIBDIR}/examples

.include "../../mk/emacs.mk"
.include "../../mk/bsd.pkg.mk"
