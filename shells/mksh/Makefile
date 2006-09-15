# $NetBSD: Makefile,v 1.1.1.1 2006/09/15 13:00:37 joerg Exp $

DISTNAME=			mksh-R28
PKGNAME=			mksh-28
CATEGORIES=			shells
MASTER_SITES=			http://www.mirbsd.org/MirOS/dist/mir/mksh/
EXTRACT_SUFX=			.cpio.gz

MAINTAINER=			pkgsrc-users@NetBSD.org
HOMEPAGE=			http://mirbsd.de/mksh
COMMENT=			MirBSD Korn Shell

WRKSRC=				${WRKDIR}/mksh
WRKBUILD?=			${WRKSRC}

PKG_INSTALLATION_TYPES=		pkgviews overwrite
PKG_SHELL=			bin/mksh

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=		PKG_OPTIONS.mksh
PKG_SUPPORTED_OPTIONS=		static
PKG_SUGGESTED_OPTIONS=		static

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mstatic)
LDFLAGS+=			-static
.endif

LIBS+=				${LDADD}
.if ${OPSYS} == "Interix"
LIBS+=				-lcrypt
.endif

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/examples/mksh

do-build:
	cd ${WRKBUILD} && LIBS=${LIBS:Q} CC=${CC:Q} CFLAGS=${CFLAGS:Q} \
	    CPPFLAGS=${CPPFLAGS:Q} LDFLAGS=${LDFLAGS:Q} \
	    ${TOOLS_SHELL} ${WRKSRC}/Build.sh ${BUILD_PARMS}

do-install:
	${INSTALL_PROGRAM} ${WRKBUILD}/mksh ${PREFIX}/bin/mksh
	${INSTALL_MAN} ${WRKSRC}/mksh.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/dot.mkshrc ${PREFIX}/share/examples/mksh

#USE_TOOLS+=			ed:test perl:test
#do-test:
#	${WRKBUILD}/test.sh -v

.include "../../mk/bsd.pkg.mk"
