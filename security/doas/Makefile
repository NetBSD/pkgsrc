# $NetBSD: Makefile,v 1.5 2019/11/29 15:27:42 ng0 Exp $

DISTNAME=	doas-6.2p2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=slicer69/}

MAINTAINER=	ng0@NetBSD.org
HOMEPAGE=	https://github.com/slicer69/doas/
COMMENT=	Execute commands as another user
LICENSE=	2-clause-bsd AND isc AND modified-bsd

USE_TOOLS+=	gmake yacc

# XXX: Upstream supports only NetBSD, FreeBSD, Linux,
# illumos, SmartOS, OpenIndiana.
# Add any failing platforms as BROKEN_ON_PLATFORM.

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-install
SUBST_MESSAGE.fix-paths=	Fixing paths.
SUBST_FILES.fix-paths=		Makefile
SUBST_SED.fix-paths+=		-e 's,$${PREFIX}/etc,${PKG_SYSCONFDIR},g'
SUBST_SED.fix-paths+=		-e 's,/man/,/${PKGMANDIR}/,g'

SPECIAL_PERMS+=		bin/doas ${SETUID_ROOT_PERMS}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5

.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
