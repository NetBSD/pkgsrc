# $NetBSD: Makefile,v 1.14 2021/01/01 14:21:23 pin Exp $

DISTNAME=	doas-6.3p2
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=slicer69/}

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://github.com/slicer69/doas/
COMMENT=	Execute commands as another user
LICENSE=	2-clause-bsd AND isc AND modified-bsd

CONFLICTS=	opendoas-[0-9]*

USE_TOOLS+=	gmake yacc

# Upstream supports only NetBSD, FreeBSD, Linux,
# illumos, SmartOS, OmniOS and macOS Catalina.
# Add any failing platforms as BROKEN_ON_PLATFORM.

MAKE_FLAGS+=	MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}
MAKE_ENV+=	SYSCONFDIR=${PKG_SYSCONFDIR:Q}

SPECIAL_PERMS+=		bin/doas ${SETUID_ROOT_PERMS}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5

# Security concerns have been raised by kim@netbsd.org
# regarding the vidoas functionality in pkgsrc-security.
# Remove this functionality until the situation is clarified
# with upstream, https://github.com/slicer69/doas/pull/46

post-install:
	${RM} -rf ${DESTDIR}${PREFIX}/bin/vidoas

.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
