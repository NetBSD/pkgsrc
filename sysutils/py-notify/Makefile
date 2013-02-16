# $NetBSD: Makefile,v 1.29 2013/02/16 11:19:22 wiz Exp $
#

DISTNAME=	notify-python-0.1.1
PKGNAME=	${PYPKGPREFIX}-notify-0.1.1
PKGREVISION=	17
CATEGORIES=	sysutils
MASTER_SITES= \
 http://www.galago-project.org/files/releases/source/notify-python/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.galago-project.org/
COMMENT=	Python bindings for libnotify

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	notify-python.pc.in
PY_PATCHPLIST=	yes

# Missing function attach_status_icon
# http://trac.galago-project.org/ticket/121
post-extract:
	${RM} -f ${WRKSRC}/src/pynotify.c

.include "../../lang/python/extension.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
