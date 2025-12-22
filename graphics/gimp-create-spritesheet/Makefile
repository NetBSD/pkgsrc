# $NetBSD: Makefile,v 1.5 2025/12/22 11:31:40 wiz Exp $

DISTNAME=		create_spritesheet
PKGNAME=		gimp-create-spritesheet-0.0.2019.11.27
PKGREVISION=		3
CATEGORIES=		graphics
MASTER_SITES=		https://raw.githubusercontent.com/Spydarlee/scripts/master/GIMP/
DIST_SUBDIR=		${PKGNAME_NOREV}
EXTRACT_SUFX=		.py

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		https://karnbianco.co.uk/blog/2018/04/10/tutorial-animated-spritesheets-with-gimp-and-unity/
COMMENT=		Spritesheet creation plugin for gimp
LICENSE=		public-domain

DEPENDS+=		gimp-[0-9]*:../../graphics/gimp

WRKSRC=			${WRKDIR}
REPLACE_PYTHON=		${DISTNAME}.py
INSTALLATION_DIRS=	lib/gimp/3.0/plug-ins
USE_LANGUAGES=		# python

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME}.py ${DESTDIR}${PREFIX}/lib/gimp/3.0/plug-ins/

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
