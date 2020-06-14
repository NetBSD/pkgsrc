# $NetBSD: Makefile,v 1.3 2020/06/14 10:38:11 ryoon Exp $

DISTNAME=	RETRO${RETRO_REL}-${RETRO_SNAPSHOT}
PKGNAME=	forth-retro-${RETRO_REL}.0.${RETRO_SNAPSHOT}
CATEGORIES=	lang
MASTER_SITES=	https://forthworks.com/retro/r/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://forthworks.com/retro/
COMMENT=	Clean, elegant, and pragmatic dialect of Forth
LICENSE=	isc

RETRO_REL=	12
RETRO_SNAPSHOT=	2019.7

MAKE_JOBS_SAFE=	no

LDFLAGS.SunOS+=	-lsocket -lnsl

REPLACE_INTERPRETER+=	retro
REPLACE.retro.old=	.*retro
REPLACE.retro.new=	${PREFIX}/bin/retro
REPLACE_FILES.retro=	retro-describe.forth

.include "../../mk/bsd.pkg.mk"
