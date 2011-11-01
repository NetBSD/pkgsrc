# $NetBSD: Makefile,v 1.19 2011/11/01 06:02:35 sbd Exp $
#

DISTNAME=	notify-python-0.1.1
PKGNAME=	${PYPKGPREFIX}-notify-0.1.1
PKGREVISION=	9
CATEGORIES=	sysutils
MASTER_SITES= \
 http://www.galago-project.org/files/releases/source/notify-python/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.galago-project.org/
COMMENT=	Python bindings for libnotify

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	notify-python.pc.in
PYTHON_VERSIONS_ACCEPTED=	27 26 25
PY_PATCHPLIST=	yes

# Missing function attach_status_icon
# http://trac.galago-project.org/ticket/121
post-extract:
	${RM} -f ${WRKSRC}/src/pynotify.c

.include "../../lang/python/extension.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
