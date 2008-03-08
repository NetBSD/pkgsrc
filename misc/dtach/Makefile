# $NetBSD: Makefile,v 1.6 2008/03/08 01:06:50 obache Exp $

DISTNAME=	dtach-0.8
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dtach/}

MAINTAINER=	fgudin@nerim.net
HOMEPAGE=	http://dtach.sourceforge.net/
COMMENT=	Small program that emulates the detach feature of screen

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
BUILD_TARGET=	dtach

DOCS=		COPYING README dtach.spec
DOCDIR=		${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/dtach ${DESTDIR}${PREFIX:Q}/bin
	${INSTALL_MAN} ${WRKSRC:Q}/dtach.1				\
		${DESTDIR}${PREFIX:Q}/${PKGMANDIR:Q}/man1
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR:Q}
	cd ${WRKSRC:Q}; for f in ${DOCS}; do				\
		${INSTALL_DATA} $$f ${DESTDIR}${DOCDIR}/$$f;		\
	done

.include "../../mk/bsd.pkg.mk"
