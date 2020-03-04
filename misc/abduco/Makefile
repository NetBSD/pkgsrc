# $NetBSD: Makefile,v 1.4 2020/03/04 20:56:01 nia Exp $

DISTNAME=	abduco-0.6
CATEGORIES=	misc
MASTER_SITES=	https://www.brain-dump.org/projects/abduco/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.brain-dump.org/projects/abduco/
COMMENT=	Tool for session {at,de}tach support
LICENSE=	isc

USE_LANGUAGES=	c99

MAKE_FLAGS+=	MANPREFIX=${PREFIX}/${PKGMANDIR}

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE
CFLAGS.Darwin+=	-D_DARWIN_C_SOURCE

.include "../../mk/bsd.pkg.mk"
