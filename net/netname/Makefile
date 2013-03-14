# $NetBSD: Makefile,v 1.14 2013/03/14 14:15:00 kim Exp $
#

DISTNAME=	netname-2.2
CATEGORIES=	net
MASTER_SITES=	http://oss.gw.com/people/kim/

MAINTAINER=	kim@tac.nyc.ny.us
COMMENT=	Return the canonical network name of a host

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
BUILD_TARGET=	svr4
.else
BUILD_TARGET=	netname
.endif
INSTALL_TARGET=	inst-all

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

MAKE_ENV+=	INSTALL=${TOOLS_PATH.install:Q}

SUBST_CLASSES+=		manpath
SUBST_STAGE.manpath=	post-extract
SUBST_FILES.manpath=	Makefile
SUBST_SED.manpath=	-e 's,/man/,/${PKGMANDIR}/,'

.include "../../mk/bsd.pkg.mk"
