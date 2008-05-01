# $NetBSD: Makefile,v 1.9 2008/05/01 13:51:56 obache Exp $
#

.include "../../textproc/catdoc/Makefile.common"

PKGNAME=		${DISTNAME:S/catdoc/catdoc-tk/}
COMMENT=		Reads MS-Word file and puts out its content as plain text (Tk interface)

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		catdoc>=0.91.4nb1:../../textproc/catdoc

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
