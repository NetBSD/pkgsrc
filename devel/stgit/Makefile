# $NetBSD: Makefile,v 1.4 2008/01/30 23:03:50 bjs Exp $

DISTNAME=	stgit-20080128
CATEGORIES=	devel
MASTER_SITES=	http://homepage.ntlworld.com/cmarinas/stgit/snapshots/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.procode.org/stgit/
COMMENT=	Stacked GIT

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	scmgit-base-[0-9]*:../../devel/scmgit-base

USE_TOOLS+= 	bash:run

REPLACE_BASH= 	contrib/stg-*

PYTHON_VERSIONS_ACCEPTED?=24 23
PYTHON_PATCH_SCRIPTS=	*.py stgit/*.py
PYDISTUTILSPKG=		yes
PYSETUPINSTALLARGS=	--prefix=${PREFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"

pre-install:
	${CHMOD} a-x ${WRKSRC}/contrib/stgbashprompt.sh

post-install:
	${RM} ${WRKSRC}/contrib/*.orig && \
	${INSTALL_SCRIPT_DIR} ${DESTDIR}${PREFIX}/bin && \
	for fn in ${WRKSRC}/contrib/stg-*; do \
		${INSTALL_SCRIPT} $$fn ${DESTDIR}${PREFIX}/bin; \
	done;

.include "../../mk/bsd.pkg.mk"
