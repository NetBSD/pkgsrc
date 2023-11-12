# $NetBSD: Makefile,v 1.23 2023/11/12 13:23:41 wiz Exp $

PKGREVISION= 1
.include "../../textproc/catdoc/Makefile.common"

PKGNAME=	${DISTNAME:S/catdoc-/catdoc-tk-/}
COMMENT=	Tk interface for MS-Word to plain text converter

DEPENDS+=	catdoc>=0.95:../../textproc/catdoc

CONFIGURE_ARGS+=	--enable-wordview
CONFIGURE_ENV+=		WISH="${BUILDLINK_PREFIX.tk}/bin/wish"

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-build:
	cd ${WRKSRC}/src && ${MAKE} wordview

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/wordview ${DESTDIR}${PREFIX}/bin/wordview
	${INSTALL_MAN} ${WRKSRC}/doc/wordview.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
