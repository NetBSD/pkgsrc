# $NetBSD: Makefile,v 1.5 2020/03/16 13:42:15 tnn Exp $

DISTNAME=	syncffsd-0.8
CATEGORIES=	net
MASTER_SITES=	http://ftp.espci.fr/pub/syncffsd/
EXTRACT_SUFX=	.tgz

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	https://ftp.espci.fr/pub/syncffsd/
COMMENT=	FFS file system mirroring using rsync
LICENSE=	modified-bsd

ONLY_FOR_PLATFORM+=	NetBSD-*-*
RCD_SCRIPTS=		syncffsd

BUILD_DEFS+=	VARBASE
MAKE_ENV+=	VARBASE=${VARBASE}
MAKE_ENV+=	PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
