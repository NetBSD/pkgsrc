# $NetBSD: Makefile,v 1.1 2020/03/04 20:30:50 nia Exp $

DISTNAME=	abduco-0.6
CATEGORIES=	misc
MASTER_SITES=	https://www.brain-dump.org/projects/abduco/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.brain-dump.org/projects/abduco/
COMMENT=	Tool for session {at,de}tach support
LICENSE=	isc

USE_TOOLS+=	gmake

MAKE_FLAGS+=	MANPREFIX=${PREFIX}/${PKGMANDIR}

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

.include "../../mk/bsd.pkg.mk"
