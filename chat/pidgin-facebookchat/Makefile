# $NetBSD: Makefile,v 1.40 2020/11/05 09:07:35 ryoon Exp $

DISTNAME=	pidgin-facebookchat-source-1.69
PKGNAME=	${DISTNAME:S/-source-/-/}
PKGREVISION=	20
CATEGORIES=	chat
MASTER_SITES=	http://pidgin-facebookchat.googlecode.com/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/dequis/purple-facebook
COMMENT=	Plugin for pidgin to support Facebook IM
LICENSE=	gnu-gpl-v3 # or later

DEPENDS+=	pidgin>=2.7.9:../../chat/pidgin

WRKSRC=		${WRKDIR}/${PKGBASE}

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Fixing absolute paths.
SUBST_FILES.paths=	Makefile
SUBST_SED.paths=	-e 's+-I/usr/include/glib-2.0 -I/usr/lib/glib-2.0/include+-I${BUILDLINK_PREFIX.glib2}/include/glib/glib-2.0/glib -I${BUILDLINK_PREFIX.glib2}/include/glib/glib-2.0 -I${BUILDLINK_PREFIX.glib2}/lib/glib-2.0/include+g'
SUBST_SED.paths+=	-e 's+-I/usr/include/libpurple+-I${BUILDLINK_PREFIX.libpurple}/include/libpurple+g'
SUBST_SED.paths+=	-e 's+-I/usr/include/json-glib-1.0+-I${BUILDLINK_PREFIX.json-glib}/include/json-glib-1.0+g'
SUBST_SED.paths+=	-e 's+/usr/share/+${DESTDIR}${PREFIX}/share/+g'
SUBST_SED.paths+=	-e 's+/usr/lib/+${DESTDIR}${PREFIX}/lib/+g'

INSTALLATION_DIRS+=	lib/purple-2

.include "../../chat/libpurple/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.json-glib+=	json-glib>=0.7.6
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
