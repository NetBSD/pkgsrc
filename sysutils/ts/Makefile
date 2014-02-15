# $NetBSD: Makefile,v 1.3 2014/02/15 22:32:10 wiedi Exp $
#

DISTNAME=	ts-0.7.0
CATEGORIES=	sysutils
MASTER_SITES=	http://vicerveza.homeunix.net/~viric/soft/ts/

MAINTAINER=	jan.smydke@jh-inst.cas.cz
HOMEPAGE=	http://vicerveza.homeunix.net/~viric/soft/ts/
COMMENT=	Simple handy batch system
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c
USE_TOOLS+=	gmake

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../mk/bsd.pkg.mk"
