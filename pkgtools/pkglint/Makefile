# $NetBSD: Makefile,v 1.554 2018/11/07 20:58:22 rillig Exp $

PKGNAME=	pkglint-5.6.6
DISTFILES=	# none
CATEGORIES=	pkgtools

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	https://github.com/rillig/pkglint
COMMENT=	Verifier for NetBSD packages
LICENSE=	2-clause-bsd
CONFLICTS+=	pkglint4-[0-9]*

NO_CHECKSUM=	yes
USE_TOOLS+=	pax
AUTO_MKDIRS=	yes
GO_SRCPATH=	netbsd.org/pkglint

CHECK_RELRO_SKIP+=	bin/pkglint

SUBST_CLASSES+=		pkglint
SUBST_STAGE.pkglint=	post-configure
SUBST_FILES.pkglint+=	pkglint.go
SUBST_SED.pkglint+=	-e s\|@VERSION@\|${PKGNAME:S/pkglint-//}\|g
SUBST_SED.pkglint+=	-e s\|@BMAKE@\|${MAKE:T:Q}\|g

TOOLS_CREATE+=		goyacc
TOOLS_PATH.goyacc=	${WRKDIR}/bin/goyacc
USE_TOOLS+=		goyacc

do-extract:
	${RUN} ${MKDIR} ${WRKDIR}/pkglint
	${RUN} cd ${FILESDIR} && ${PAX} -rw . ${WRKDIR}/pkglint
	${RUN} ${PKGSRC_SETENV} ${MAKE_ENV} ${GO} get golang.org/x/tools/cmd/goyacc
	${RUN} ${PKGSRC_SETENV} ${MAKE_ENV} ${GO} install golang.org/x/tools/cmd/goyacc

pre-build:
	${RUN} ${PKGSRC_SETENV} ${MAKE_ENV} ${GO} generate ${GO_BUILD_PATTERN}

pre-install:
	${RUN} rm -f ${WRKDIR}/bin/goyacc
	${RUN} rm -rf ${WRKDIR}/pkg

post-install: do-install-man

# This needs to come before bsd.prefs.mk so that SSP_SUPPORTED is properly set.
.include "../../lang/go/go-package.mk"

.include "../../mk/bsd.prefs.mk"

do-install-man: .PHONY
.if ${MANINSTALL:Mcatinstall}
.  if ${CATMAN_SECTION_SUFFIX:M[Yy][Ee][Ss]}
	${INSTALL_MAN} ${WRKSRC}/pkglint.0 ${DESTDIR}${PREFIX}/${PKGMANDIR}/cat1/pkglint.1
.  else
	${INSTALL_MAN} ${WRKSRC}/pkglint.0 ${DESTDIR}${PREFIX}/${PKGMANDIR}/cat1
.  endif
.endif
.if ${MANINSTALL:Mmaninstall}
	${INSTALL_MAN} ${WRKSRC}/pkglint.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.endif

.if !empty(PKGSRC_RUN_TEST:M[yY][eE][sS])
.  include "../../devel/go-check/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
