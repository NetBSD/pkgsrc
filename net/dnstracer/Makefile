# $NetBSD: Makefile,v 1.12 2014/02/26 18:17:39 wiedi Exp $

DISTNAME=		dnstracer-1.9
CATEGORIES=		net
MASTER_SITES=		http://www.mavetju.org/download/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.mavetju.org/unix/general.php
COMMENT=		Tool to trace dns queries

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_FEATURES+=		inet6

LDFLAGS.SunOS+=		-lresolv -lsocket -lnsl

.include "../../mk/bsd.pkg.mk"
