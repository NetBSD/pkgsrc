# $NetBSD: Makefile,v 1.2 2019/08/24 15:46:59 ng0 Exp $

DISTNAME=	doas-6.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=slicer69/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/slicer69/doas/
COMMENT=	Execute commands as another user
LICENSE=	2-clause-bsd AND isc AND modified-bsd

USE_TOOLS+=	gmake yacc

# XXX: Upstream supports only NetBSD, FreeBSD, and Linux.
# Add any failing platforms as BROKEN_ON_PLATFORM.

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-install
SUBST_MESSAGE.fix-paths=	Fixing paths.
SUBST_FILES.fix-paths=		Makefile
SUBST_SED.fix-paths+=		-e 's,$${PREFIX}/etc,${PKG_SYSCONFDIR},g'
SUBST_SED.fix-paths+=		-e 's,$$(PREFIX),$$(DESTDIR)$$(PREFIX),g'
SUBST_SED.fix-paths+=		-e 's,/man/,/${PKGMANDIR}/,g'

SPECIAL_PERMS+=		bin/doas ${SETUID_ROOT_PERMS}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5

.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
