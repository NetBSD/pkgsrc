# $NetBSD: Makefile,v 1.738 2023/01/29 13:36:31 rillig Exp $

PKGNAME=	pkglint-22.4.0
CATEGORIES=	pkgtools

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	https://github.com/rillig/pkglint
COMMENT=	Verifier for NetBSD packages
LICENSE=	2-clause-bsd
CONFLICTS+=	pkglint4-[0-9]*

USE_TOOLS+=		pax
CHECK_RELRO_SKIP+=	bin/pkglint


SUBST_CLASSES+=		pkglint
SUBST_STAGE.pkglint=	post-configure
SUBST_FILES.pkglint+=	pkglint.go
SUBST_SED.pkglint+=	-e s\|@VERSION@\|${PKGVERSION}\|g
SUBST_SED.pkglint+=	-e s\|@BMAKE@\|${MAKE:T:Q}\|g

EXTRACT_PAX_ARGS=	-s ',.*/CVS$$,,' -s ',.*/CVS/.*,,' -s ',.*/\..*,,'

TOOL_DEPENDS+=		go-tools-[0-9]*:../../devel/go-tools

do-extract:
	${RUN} ${MKDIR} ${WRKSRC}
	${RUN} cd ${FILESDIR} && ${PAX} -rw ${EXTRACT_PAX_ARGS} . ${WRKSRC}

pre-build:
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ${GO} generate ${GO_BUILD_PATTERN}

do-test:
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ${GO} test -vet=off -v ${GO_BUILD_PATTERN}

post-install: do-install-man

.include "go-modules.mk"

# This needs to come before bsd.prefs.mk so that SSP_SUPPORTED is properly set.
.include "../../lang/go/go-module.mk"

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		catinstall0 catinstall maninstall
.if ${MANINSTALL:Mcatinstall}
INSTALLATION_DIRS+=	man/cat1
.  if ${CATMAN_SECTION_SUFFIX:U:tl} == yes
PLIST.catinstall=	yes
.  else
PLIST.catinstall0=	yes
.  endif
.endif
.if ${MANINSTALL:Mmaninstall}
INSTALLATION_DIRS+=	man/man1
PLIST.maninstall=	yes
.endif

do-install-man: .PHONY
	${PLIST.catinstall:D:U\:} ${INSTALL_MAN} ${WRKSRC}/pkglint.0 ${DESTDIR}${PREFIX}/${PKGMANDIR}/cat1/pkglint.1
	${PLIST.catinstall0:D:U\:} ${INSTALL_MAN} ${WRKSRC}/pkglint.0 ${DESTDIR}${PREFIX}/${PKGMANDIR}/cat1/
	${PLIST.maninstall:D:U\:} ${INSTALL_MAN} ${WRKSRC}/pkglint.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../mk/bsd.pkg.mk"
