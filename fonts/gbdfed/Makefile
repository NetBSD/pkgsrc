# $NetBSD: Makefile,v 1.1.1.1 2008/08/09 19:52:02 bjs Exp $
#

DISTNAME=	gbdfed-1.4
CATEGORIES=	fonts
MASTER_SITES=	http://www.math.nmsu.edu/~mleisher/Software/gbdfed/
EXTRACT_SUFX=	.tbz2

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	gbdfed-1.4-patch1
PATCH_DIST_STRIP=	-p1

MAINTAINER=	bjs@NetBSD.org
HOMEPAGE=	http://www.math.nmsu.edu/~mleisher/Software/gbdfed/
COMMENT=	GTK-based BDF font editor

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes

AUTO_MKDIRS=	yes
BINDIR=		${PREFIX}/bin
MAN1DIR=	${PREFIX}/${PKGMANDIR}/man1

do-install:
	cd ${WRKSRC:Q} && \
		${LIBTOOL} --mode=install ${INSTALL_PROGRAM} gbdfed \
			${DESTDIR:Q}${BINDIR:Q} && \
		${INSTALL_MAN} gbdfed.man ${DESTDIR:Q}${MAN1DIR:Q}/gbdfed.1

.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
