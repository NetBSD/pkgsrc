# $NetBSD: Makefile,v 1.2 2004/03/08 20:27:16 minskim Exp $
#

.include "../../textproc/catdoc/Makefile.common"

PKGNAME=		${DISTNAME:S/catdoc/catdoc-tk/}
COMMENT+=		(Tk interface)

DEPENDS+=		catdoc>=0.91.4nb1:../../textproc/catdoc

USE_X11=		yes

CONFIGURE_ARGS+=	--enable-wordview
CONFIGURE_ENV+=		WISH="${BUILDLINK_PREFIX.tk}/bin/wish"
CONFIGURE_ENV+=		enable_wordview=yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/wordview ${PREFIX}/bin/wordview

.include "../../x11/tk83/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
