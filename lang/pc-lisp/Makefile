# $NetBSD: Makefile,v 1.1 2018/02/03 20:26:31 kamil Exp $

DISTNAME=	master
# There is no exact version available; use VERSION from lisp.h
PKGNAME=	pc-lisp-6.0
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GITHUB:=blakemcbride/}
DIST_SUBDIR=	${GITHUB_PROJECT}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/blakemcbride/PC-LISP/
COMMENT=	Franz Lisp dialect Lisp system
LICENSE=	2-clause-bsd

GITHUB_PROJECT=	PC-LISP
GITHUB_TAG=	2b50414e258a3916bf19d1b354f4c4e647eb7bb8

USE_TOOLS+=	gmake

BUILD_DIRS=	src
BUILD_TARGET=	pc-lisp

INSTALLATION_DIRS=	bin share/doc/${PKGBASE} share/${PKGBASE}

do-install:
	${RUN} ${INSTALL_PROGRAM} \
		${WRKSRC}/src/pc-lisp \
		${DESTDIR}${PREFIX}/bin

.for f in README.md Franz_Lisp_July_1983.pdf pc-lisp.doc
	${RUN} ${INSTALL_DATA} \
		${WRKSRC}/${f} \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/${f}
.endfor

.for f in diff.l dragon.l hanoi.l if.l match.l pc-lisp.l qanda.l queens.l \
          turtle.l
	${RUN} ${INSTALL_SCRIPT} \
		${WRKSRC}/${f} \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/${f}
	${RUN} ${CHMOD} -x ${DESTDIR}${PREFIX}/share/${PKGBASE}/${f}
.endfor

.include "../../mk/bsd.pkg.mk"
