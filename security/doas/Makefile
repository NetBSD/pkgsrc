# $NetBSD: Makefile,v 1.11 2020/10/21 17:34:09 kim Exp $

DISTNAME=	doas-6.2p4
PKGREVISION=	3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=slicer69/}

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://github.com/slicer69/doas/
COMMENT=	Execute commands as another user
LICENSE=	2-clause-bsd AND isc AND modified-bsd

USE_TOOLS+=	gmake yacc

# XXX: Upstream supports only NetBSD, FreeBSD, Linux,
# illumos, SmartOS, OpenIndiana.
# Add any failing platforms as BROKEN_ON_PLATFORM.

MAKE_ENV+=	MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}
MAKE_ENV+=	SYSCONFDIR=${PKG_SYSCONFDIR:Q}

SPECIAL_PERMS+=		bin/doas ${SETUID_ROOT_PERMS}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5

.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
