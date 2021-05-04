# $NetBSD: Makefile,v 1.9 2021/05/04 14:41:52 prlw1 Exp $

DISTNAME=	vtkDocHtml-9.0.1
PKGNAME=	${DISTNAME:S/vtkDocHtml/vtk-docs/}
CATEGORIES=	graphics
MASTER_SITES=	https://www.vtk.org/files/release/9.0/

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://vtk.org/
COMMENT=	Documentation for VTK (HTML)
LICENSE=	modified-bsd

USE_TOOLS+=	pax
WRKSRC=		${WRKDIR}/html
NO_CONFIGURE=	yes
NO_BUILD=	yes

HTML_DIR=		share/doc/${PKGNAME}
INSTALLATION_DIRS+=	${HTML_DIR}

do-install:
	cd ${WRKSRC} && ${PAX} -rw -pam . ${DESTDIR}${PREFIX}/${HTML_DIR}

.include "../../mk/bsd.pkg.mk"
