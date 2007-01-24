# $NetBSD: Makefile,v 1.8 2007/01/24 17:07:00 reed Exp $
#

.include "../../textproc/catdoc/Makefile.common"

PKGNAME=		${DISTNAME:S/catdoc/catdoc-tk/}
COMMENT=		Reads MS-Word file and puts out its content as plain text (Tk interface)

DEPENDS+=		catdoc>=0.91.4nb1:../../textproc/catdoc

CONFIGURE_ARGS+=	--enable-wordview
CONFIGURE_ENV+=		WISH="${BUILDLINK_PREFIX.tk}/bin/wish"
CONFIGURE_ENV+=		enable_wordview=yes

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-build:
	cd ${WRKSRC}/src && ${MAKE} wordview

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/wordview ${PREFIX}/bin/wordview
	${INSTALL_MAN} ${WRKSRC}/doc/wordview.1 ${PREFIX}/${PKGMANDIR}/man1/

.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
