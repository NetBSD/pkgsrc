# $NetBSD: Makefile,v 1.34 2021/04/21 11:40:39 adam Exp $

DISTNAME=	notify-python-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	40
CATEGORIES=	sysutils
MASTER_SITES=	http://www.galago-project.org/files/releases/source/notify-python/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.galago-project.org/
COMMENT=	Python bindings for libnotify
LICENSE=	gnu-lgpl-v2.1

CONFLICTS=	${PYPKGPREFIX}-notify<=0.1.1nb17
SUPERSEDES=	${PYPKGPREFIX}-notify<=0.1.1nb17

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=		notify-python.pc.in
PY_PATCHPLIST=			yes
PYTHON_VERSIONS_ACCEPTED=	27 # py-gtk2

# Missing function attach_status_icon
# http://trac.galago-project.org/ticket/121
post-extract:
	${RM} -f ${WRKSRC}/src/pynotify.c

.include "../../lang/python/extension.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
