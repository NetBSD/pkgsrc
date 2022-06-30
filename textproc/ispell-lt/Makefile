# $NetBSD: Makefile,v 1.15 2022/06/30 11:18:54 nia Exp $

DISTNAME=	ispell-lt-1.3
PKGREVISION=	3
CATEGORIES=	textproc
#MASTER_SITES=	ftp://ftp.akl.lt/ispell-lt/

MAINTAINER=	tomas.furmonavicius@takas.lt
HOMEPAGE=	https://launchpad.net/ispell-lt
COMMENT=	Lithuanian dictionary for ispell
LICENSE=	modified-bsd

DEPENDS+=	ispell-[0-9]*:../../textproc/ispell

USE_TOOLS+=			gmake
REPLACE_PYTHON+=		tools/*.py
PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 1.3

SUBST_CLASSES+=		install
SUBST_FILES.install=	Makefile
SUBST_MESSAGE.install=	Fixing DESTDIR path and install user/group.
SUBST_SED.install=	-e "s|D_INSTALL = |D_INSTALL = ${DESTDIR}|1"
SUBST_SED.install+=	-e 's/-g 0 -o 0//g'
SUBST_STAGE.install=	pre-configure

BUILD_TARGET=		lietuviu.hash
INSTALLATION_DIRS+=	lib

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
