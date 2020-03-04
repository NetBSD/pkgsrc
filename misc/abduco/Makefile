# $NetBSD: Makefile,v 1.3 2020/03/04 20:50:11 nia Exp $

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

.include "../../mk/bsd.pkg.mk"
