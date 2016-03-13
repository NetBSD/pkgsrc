# $NetBSD: Makefile,v 1.483 2016/03/13 13:40:10 rillig Exp $

PKGNAME=	pkglint-5.3.6
DISTFILES=	# none
CATEGORIES=	pkgtools

OWNER=		rillig@NetBSD.org
HOMEPAGE=	http://www.NetBSD.org/docs/pkgsrc/
COMMENT=	Verifier for NetBSD packages
LICENSE=	2-clause-bsd
CONFLICTS+=	pkglint4-[0-9]*

WRKSRC=		${WRKDIR}/netbsd.org/pkglint
NO_CHECKSUM=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	pax
AUTO_MKDIRS=	yes
GO_SRCPATH=	netbsd.org/pkglint

SUBST_CLASSES+=		pkglint
SUBST_STAGE.pkglint=	post-configure
SUBST_FILES.pkglint+=	main.go
SUBST_SED.pkglint+=	-e s\|@VERSION@\|${PKGNAME:S/pkglint-//}\|g
SUBST_SED.pkglint+=	-e s\|@BMAKE@\|${MAKE:Q}\|g

do-extract:
	${RUN} mkdir -p ${WRKDIR}/pkglint/plist-clash
	${RUN} cd ${FILESDIR} && ${PAX} -rw *.go */*.go pkglint.[01] ${WRKDIR}/pkglint

do-install: do-install-man

.include "../../mk/bsd.prefs.mk"

do-install-man: .PHONY
.if !empty(MANINSTALL:Mcatinstall)
.  if defined(CATMAN_SECTION_SUFFIX) && !empty(CATMAN_SECTION_SUFFIX:M[Yy][Ee][Ss])
	${INSTALL_MAN} ${WRKSRC}/pkglint.0 ${DESTDIR}${PREFIX}/${PKGMANDIR}/cat1/pkglint.1
.  else
	${INSTALL_MAN} ${WRKSRC}/pkglint.0 ${DESTDIR}${PREFIX}/${PKGMANDIR}/cat1
.  endif
.endif
.if !empty(MANINSTALL:Mmaninstall)
	${INSTALL_MAN} ${WRKSRC}/pkglint.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.endif

.include "../../lang/go/go-package.mk"
.if !empty(PKGSRC_RUN_TEST:M[yY][eE][sS])
.include "../../devel/go-check/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
