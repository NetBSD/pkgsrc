# $NetBSD: Makefile,v 1.1.1.1 2003/01/22 22:41:23 kristerw Exp $
#

DISTNAME=	twelf-1-4
PKGNAME=	twelf-1.4
CATEGORIES=	lang
MASTER_SITES=	http://www.cs.cmu.edu/~twelf/dist/

MAINTAINER=	richards+netbsd@CS.Princeton.EDU
HOMEPAGE=	http://www.cs.cmu.edu/~twelf/
COMMENT=	Meta-language for proving properties of languages and logics

DEPENDS+=	sml-nj>=110.38:../../lang/sml-nj

RESTRICTED=	License terms not specified; assume no redistribution rights
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

WRKSRC=		${WRKDIR}/twelf
MAKEFILE=	smlnj/Makefile
MAKEFLAGS+=	sml=${PREFIX:Q}/bin/sml
ALL_TARGET=	twelf-server twelf-sml

TWELF_LIBDIR=		${PREFIX}/lib/twelf
TWELF_EMACSDIR=		${EMACS_LISPPREFIX}/twelf
TWELF_DOCDIR=		${PREFIX}/share/doc/twelf
TWELF_EXAMPLEDIR=	${PREFIX}/share/examples/twelf

# 
# Everything up until "post-extract" is taken from lang/sml-nj/Makefile.
# There ought to be a buildlink2.mk for SML/NJ instead, since every
# SML/NJ-built package will require this kind of PLIST handling.
#

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
OS=		${LOWER_OPSYS}
.elif ${OPSYS} == "NetBSD"
OS=		bsd
.endif

.if ${MACHINE_ARCH} == "sparc"
BOX=		sparc
.elif ${MACHINE_ARCH} == "i386"
BOX=		x86
.endif

PLIST_SUBST+=	BOX=${BOX} OS=${OS}

post-extract:
	${CHMOD} -R +r ${WRKSRC}

post-patch:
.for f in bin/.mkexec emacs/twelf-init.el
	${CP} ${WRKSRC}/${f} ${WRKSRC}/${f}.orig
	${SED} -e 's:@TWELF_LIBDIR@:'${TWELF_LIBDIR}':g'	\
		${WRKSRC}/${f}.orig > ${WRKSRC}/${f}
.endfor

do-install:
	${INSTALL_DATA_DIR} ${TWELF_LIBDIR}
	cd ${WRKSRC} && ${PAX} -rw -pam bin ${TWELF_LIBDIR}
	${LN} -sf ${TWELF_LIBDIR}/bin/* ${PREFIX}/bin

	${INSTALL_DATA_DIR} ${TWELF_EMACSDIR}
	cd ${WRKSRC}/emacs && ${PAX} -rw -pam * ${TWELF_EMACSDIR}
	${LN} -sf ${TWELF_EMACSDIR} ${TWELF_LIBDIR}/emacs

	${INSTALL_DATA_DIR} ${TWELF_DOCDIR}
	cd ${WRKSRC}/doc && ${PAX} -rw -pam * ${TWELF_DOCDIR}
	${LN} -sf ${TWELF_DOCDIR} ${TWELF_LIBDIR}/doc

	${INSTALL_DATA_DIR} ${TWELF_EXAMPLEDIR}
	cd ${WRKSRC}/examples && ${PAX} -rw -pam * ${TWELF_EXAMPLEDIR}
	${LN} -sf ${TWELF_EXAMPLEDIR} ${TWELF_LIBDIR}/examples

.include "../../mk/emacs.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
