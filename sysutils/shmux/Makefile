# $NetBSD: Makefile,v 1.3 2004/04/25 03:16:27 snj Exp $

DISTNAME=	shmux-0.10a
CATEGORIES=	sysutils
MASTER_SITES=	http://web.taranis.org/shmux/dist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	shmux@taranis.org
HOMEPAGE=	http://web.taranis.org/shmux/
COMMENT=	Shell Multiplexor

USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	shmux

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
