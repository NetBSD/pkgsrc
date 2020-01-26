# $NetBSD: Makefile,v 1.5 2020/01/26 17:32:12 rillig Exp $

DISTNAME=	ts-0.7.4
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
