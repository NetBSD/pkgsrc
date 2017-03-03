# $NetBSD: Makefile,v 1.3 2017/03/03 13:10:41 wiz Exp $

DISTNAME=	syncffsd-0.8
CATEGORIES=	net
MASTER_SITES=	http://ftp.espci.fr/pub/syncffsd/
EXTRACT_SUFX=	.tgz

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://ftp.espci.fr/pub/syncffsd/
COMMENT=	FFS file system mirroring using rsync
LICENSE=	modified-bsd

RCD_SCRIPTS=	syncffsd

MAKE_ENV+=	VARBASE=${VARBASE}
MAKE_ENV+=	PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
