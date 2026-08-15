# $NetBSD: Makefile,v 1.2 2026/08/15 06:57:50 wiz Exp $

.include "../../net/rsync/Makefile.common"

PKGNAME=		${DISTNAME:S/rsync/rrsync/}
EXTRACT_ELEMENTS=	${DISTNAME}/support/rrsync ${DISTNAME}/rrsync.1

COMMENT=		Restrict rsync users to a subdirectory via ssh logins

DEPENDS+=		rsync>=3.5.0:../../net/rsync
DEPENDS+=		${PYPKGPREFIX}-braceexpand>=0.1.7:../../textproc/py-braceexpand

USE_LANGUAGES=		# none

#NO_CONFIGURE=		yes
NO_BUILD=		yes

REPLACE_PYTHON=		support/rrsync

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	support/rrsync
SUBST_SED.paths=	-e "s|'/usr/bin/rsync'|'${PREFIX}/bin/rsync'|"

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/support/rrsync \
		${DESTDIR}${PREFIX}/bin/rrsync
	${INSTALL_MAN} ${WRKSRC}/rrsync.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/rrsync.1

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
