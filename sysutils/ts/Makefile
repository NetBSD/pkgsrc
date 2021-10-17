# $NetBSD: Makefile,v 1.6 2021/10/17 17:53:08 tm Exp $

DISTNAME=	ts-1.0.1
CATEGORIES=	sysutils
MASTER_SITES=	http://vicerveza.homeunix.net/~viric/soft/ts/

MAINTAINER=	jan.smydke@jh-inst.cas.cz
HOMEPAGE=	https://vicerveza.homeunix.net/~viric/soft/ts/
COMMENT=	Simple handy batch system
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c
USE_TOOLS+=	gmake

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../mk/bsd.pkg.mk"
