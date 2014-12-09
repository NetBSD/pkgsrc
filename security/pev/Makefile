# $NetBSD: Makefile,v 1.2 2014/12/09 13:26:40 khorben Exp $
#

DISTNAME=	pev-0.60
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pev/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://pev.sourceforge.net/
COMMENT=	The PE analysis toolkit

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}
AUTO_MKDIRS=	yes

#pre-install:
#	${MKDIR} ${DESTDIR}${PREFIX}/man/man1

.include "../../security/openssl/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
