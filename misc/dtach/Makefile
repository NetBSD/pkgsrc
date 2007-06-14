# $NetBSD: Makefile,v 1.4 2007/06/14 01:09:42 jlam Exp $

DISTNAME=	dtach-0.7
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dtach/}

MAINTAINER=	fgudin@nerim.net
HOMEPAGE=	http://dtach.sourceforge.net/
COMMENT=	Small program that emulates the detach feature of screen

GNU_CONFIGURE=	yes
BUILD_TARGET=	dtach

DOCS=		COPYING README dtach.spec
DOCDIR=		${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/dtach ${PREFIX:Q}/bin
	${INSTALL_MAN} ${WRKSRC:Q}/dtach.1 ${PREFIX:Q}/${PKGMANDIR:Q}/man1
	${INSTALL_DATA_DIR} ${DOCDIR:Q}
	cd ${WRKSRC:Q}; for f in ${DOCS}; do				\
		${INSTALL_DATA} $$f ${DOCDIR}/$$f;			\
	done

.include "../../mk/bsd.pkg.mk"
