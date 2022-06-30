# $NetBSD: Makefile,v 1.2 2022/06/30 11:18:27 nia Exp $

DISTNAME=		create_spritesheet
PKGNAME=		gimp-create-spritesheet-0.0.2019.11.27
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		https://raw.githubusercontent.com/Spydarlee/scripts/master/GIMP/
DIST_SUBDIR=		${PKGNAME_NOREV}
EXTRACT_SUFX=		.py

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://karnbianco.co.uk/blog/2018/04/10/tutorial-animated-spritesheets-with-gimp-and-unity/
COMMENT=		Spritesheet creation plugin for gimp
LICENSE=		public-domain

DEPENDS+=		gimp-[0-9]*:../../graphics/gimp

WRKSRC=			${WRKDIR}
REPLACE_PYTHON=		${DISTNAME}.py
INSTALLATION_DIRS=	lib/gimp/2.0/plug-ins
USE_LANGUAGES=		# python

# gimp python plugin support only targets python 2.7
PYTHON_VERSIONS_ACCEPTED=	27

do-build:

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME}.py ${DESTDIR}${PREFIX}/lib/gimp/2.0/plug-ins/

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
