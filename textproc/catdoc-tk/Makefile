# $NetBSD: Makefile,v 1.6 2005/06/17 03:50:36 jlam Exp $
#

.include "../../textproc/catdoc/Makefile.common"

PKGNAME=		${DISTNAME:S/catdoc/catdoc-tk/}
COMMENT+=		(Tk interface)

DEPENDS+=		catdoc>=0.91.4nb1:../../textproc/catdoc


CONFIGURE_ARGS+=	--enable-wordview
CONFIGURE_ENV+=		WISH="${BUILDLINK_PREFIX.tk}/bin/wish"
CONFIGURE_ENV+=		enable_wordview=yes

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/wordview ${PREFIX}/bin/wordview

.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
