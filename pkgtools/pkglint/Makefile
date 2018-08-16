# $NetBSD: Makefile,v 1.547 2018/08/16 20:41:42 rillig Exp $

PKGNAME=	pkglint-5.6.1
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
CHECK_RELRO_SKIP+=	bin/plist-clash

SUBST_CLASSES+=		pkglint
SUBST_STAGE.pkglint=	post-configure
SUBST_FILES.pkglint+=	pkglint.go
SUBST_SED.pkglint+=	-e s\|@VERSION@\|${PKGNAME:S/pkglint-//}\|g
SUBST_SED.pkglint+=	-e s\|@BMAKE@\|${MAKE:T:Q}\|g

do-extract:
	${RUN} ${MKDIR} ${WRKDIR}/pkglint
	${RUN} cd ${FILESDIR} && ${PAX} -rw . ${WRKDIR}/pkglint

pre-install:
	${RUN} rm -rf ${WRKDIR}/pkg

post-install: do-install-man

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

.include "../../lang/go/go-package.mk"
.if !empty(PKGSRC_RUN_TEST:M[yY][eE][sS])
.  include "../../devel/go-check/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
