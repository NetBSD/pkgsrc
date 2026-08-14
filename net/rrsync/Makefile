# $NetBSD: Makefile,v 1.1 2026/08/14 19:51:09 kim Exp $

DISTNAME=		rsync-3.5.0
PKGNAME=		${DISTNAME:S/rsync/rrsync/}
CATEGORIES=		net
MASTER_SITES=		https://rsync.samba.org/ftp/rsync/
MASTER_SITES+=		https://rsync.samba.org/ftp/rsync/old-versions/
EXTRACT_ELEMENTS=	${DISTNAME}/support/rrsync ${DISTNAME}/rrsync.1

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://rsync.samba.org/
COMMENT=		Restrict rsync users to a subdirectory via ssh logins
LICENSE=		gnu-gpl-v3

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
