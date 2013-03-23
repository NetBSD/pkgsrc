# $NetBSD: Makefile,v 1.22 2013/03/23 12:18:19 joerg Exp $

DISTNAME=			mksh-R44
PKGNAME=			${DISTNAME:S/-R/-/}
CATEGORIES=			shells
MASTER_SITES=			http://www.mirbsd.org/MirOS/dist/mir/mksh/ \
				http://pub.allbsd.org/MirOS/dist/mir/mksh/
SITES.${DISTNAME}.cat1.gz=	${MASTER_SITES:S/dist/cats/}

EXTRACT_SUFX=			.tgz

MAINTAINER=			ahoka@NetBSD.org
HOMEPAGE=			http://mirbsd.de/mksh
COMMENT=			MirBSD Korn Shell
LICENSE=			miros

WRKSRC=				${WRKDIR}/mksh
WRKBUILD?=			${WRKSRC}

PKG_INSTALLATION_TYPES=		pkgviews overwrite

PKG_SHELL=			bin/mksh

LIBS.Interix+=			-lcrypt

INSTALLATION_DIRS=		bin ${PKGMANDIR}/man1 share/examples/mksh

do-build:
	cd ${WRKBUILD} && LIBS=${LIBS:Q} CC=${CC:Q} CFLAGS=${CFLAGS:Q} \
	    CPPFLAGS=${CPPFLAGS:Q} LDFLAGS=${LDFLAGS:Q} \
	    ${TOOLS_SHELL} ${WRKSRC}/Build.sh -r

do-install:
	${INSTALL_PROGRAM} ${WRKBUILD}/mksh ${DESTDIR}${PREFIX}/bin/mksh
	${INSTALL_MAN} ${WRKSRC}/mksh.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA} ${WRKSRC}/dot.mkshrc ${DESTDIR}${PREFIX}/share/examples/mksh/

# Uncomment this if you want to run the regression tests
#USE_TOOLS+=			perl
#do-test:
#	${WRKBUILD}/test.sh -v

.include "../../mk/bsd.pkg.mk"
