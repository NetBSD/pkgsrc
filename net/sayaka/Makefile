# $NetBSD: Makefile,v 1.1 2016/02/27 14:30:58 tsutsui Exp $

DISTNAME=	sayaka-3.2.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=isaki68k/}
GITHUB_PROJECT=	${DISTNAME:S/-${PKGVERSION_NOREV}//}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	${MASTER_SITES}${GITHUB_PROJECT}
COMMENT=	Terminal specific Twitter client
LICENSE=	modified-bsd

DEPENDS+=	glib-networking-[0-9]*:../../net/glib-networking

USE_TOOLS=	pax

INSTALLATION_DIRS+=	bin share/sayaka

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Fixing ${PREFIX}
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	vala/sayaka.vala
SUBST_SED.prefix=	-e 's,@PREFIX@,${PREFIX},g'

do-build:
	cd ${WRKSRC}/vala && ${MAKE} vala-make2 && ${MAKE} sayaka

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vala/sayaka ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC} && pax -rwpp -s '/.*\.orig//' \
		*.png ${DESTDIR}${PREFIX}/share/sayaka

BUILDLINK_DEPMETHOD.vala= build
BUILDLINK_API_DEPENDS.vala+=    vala>=0.28.0
.include "../../lang/vala/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
