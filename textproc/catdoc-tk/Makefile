# $NetBSD: Makefile,v 1.19 2019/11/04 21:43:33 rillig Exp $

.include "../../textproc/catdoc/Makefile.common"

PKGNAME=	${DISTNAME:S/catdoc_/catdoc-tk-/:S/.orig//}
PKGREVISION=	2
COMMENT=	Tk interface for MS-Word to plain text converter

DEPENDS+=	catdoc>=0.94.4:../../textproc/catdoc

CONFIGURE_ARGS+=	--enable-wordview
CONFIGURE_ENV+=		WISH="${BUILDLINK_PREFIX.tk}/bin/wish"
CONFIGURE_ENV+=		enable_wordview=yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-build:
	cd ${WRKSRC}/src && ${MAKE} wordview

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/wordview ${DESTDIR}${PREFIX}/bin/wordview
	${INSTALL_MAN} ${WRKSRC}/doc/wordview.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
