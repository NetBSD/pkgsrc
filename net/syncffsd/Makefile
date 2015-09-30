# $NetBSD: Makefile,v 1.2 2015/09/30 02:03:56 manu Exp $

DISTNAME=	syncffsd-0.8
CATEGORIES=	net
MASTER_SITES=	http://ftp.espci.fr/pub/syncffsd/
EXTRACT_SUFX=	.tgz

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://ftp.espci.fr/pub/syncffsd/
COMMENT=	FFS filesystem miroring using rsync
LICENSE=	modified-bsd

RCD_SCRIPTS=	syncffsd

MAKE_ENV+=	VARBASE=${VARBASE}
MAKE_ENV+=	PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
