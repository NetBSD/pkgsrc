# $NetBSD: Makefile,v 1.18 2010/02/18 13:59:10 joerg Exp $

DISTNAME=		mdocml-1.9.15
CATEGORIES=		textproc devel
MASTER_SITES=		http://mdocml.bsd.lv/snapshots/

MAINTAINER=		kristaps@kth.se
HOMEPAGE=		http://mdocml.bsd.lv/
COMMENT=		mdoc macro compiler

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALL_MAKE_FLAGS=	PREFIX=${DESTDIR}${PREFIX} \
			MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR} \
			INSTALL_PROGRAM=${INSTALL_PROGRAM:Q}

INSTALLATION_DIRS=	share/examples/mandoc

post-install:
	${INSTALL_MAN} ${WRKSRC}/man.3 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3
	${INSTALL_MAN} ${WRKSRC}/mandoc_char.7 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man7
	${INSTALL_MAN} ${WRKSRC}/manuals.7 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man7
	${INSTALL_MAN} ${WRKSRC}/mdoc.3 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3

.include "../../mk/bsd.pkg.mk"
