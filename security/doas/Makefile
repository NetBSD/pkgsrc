# $NetBSD: Makefile,v 1.9 2020/04/28 11:46:29 nikita Exp $

DISTNAME=	doas-6.2p4
PKGREVISION=	1
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

SPECIAL_PERMS+=		bin/doas ${SETUID_ROOT_PERMS}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5

.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
