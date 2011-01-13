# $NetBSD: Makefile,v 1.22 2011/01/13 09:39:41 wiz Exp $

DISTNAME=		mdocml-1.10.9
CATEGORIES=		textproc devel
MASTER_SITES=		http://mdocml.bsd.lv/snapshots/

MAINTAINER=		kristaps@kth.se
HOMEPAGE=		http://mdocml.bsd.lv/
COMMENT=		Man page tool (mdoc macro compiler)
LICENSE=		2-clause-bsd # not exactly, but near enough

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man3 ${PKGMANDIR}/man7 share/examples/mandoc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mandoc ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man.3 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3
	${INSTALL_MAN} ${WRKSRC}/man.7 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man7/mandoc_man.7
	${INSTALL_MAN} ${WRKSRC}/mandoc_char.7 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man7
	${INSTALL_MAN} ${WRKSRC}/mdoc.7 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man7/mandoc_mdoc.7
	${INSTALL_MAN} ${WRKSRC}/mdoc.3 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3
	${INSTALL_MAN} ${WRKSRC}/roff.3 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3
	${INSTALL_MAN} ${WRKSRC}/roff.7 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man7/mandoc_roff.7
	${INSTALL_DATA} ${WRKSRC}/example.style.css ${DESTDIR}${PREFIX}/share/examples/mandoc/style.css

.include "../../mk/bsd.pkg.mk"
