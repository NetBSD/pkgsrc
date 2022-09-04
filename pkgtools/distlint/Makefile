# $NetBSD: Makefile,v 1.1 2022/09/04 21:38:47 rillig Exp $

PKGNAME=	distlint-22.09.04
CATEGORIES=	pkgtools

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.pkgsrc.org/
COMMENT=	Verify distfiles against license requirements
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}
AUTO_MKDIRS=	yes

REPLACE_PYTHON=	distlint.py

SUBST_CLASSES+=		dirs
SUBST_STAGE.dirs=	pre-configure
SUBST_FILES.dirs=	distlint.py
SUBST_VARS.dirs=	PREFIX

do-extract:
	cp ${FILESDIR}/distlint.py ${WRKSRC}

do-build:
	# Nothing

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/distlint.py ${DESTDIR}${PREFIX}/bin/distlint

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
