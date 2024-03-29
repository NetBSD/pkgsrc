# $NetBSD: Makefile,v 1.37 2022/12/31 21:49:33 plunky Exp $
#

DISTNAME=	obexapp-1.4.15
PKGREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	https://people.freebsd.org/~emax/obexapp/

MAINTAINER=	plunky@NetBSD.org
HOMEPAGE=	https://people.freebsd.org/~emax/obexapp/
COMMENT=	Obex application to transfer objects to mobile equipment
LICENSE=	modified-bsd

ONLY_FOR_PLATFORM=	FreeBSD-*-* NetBSD-[4-9].*-* NetBSD-[1-9][0-9].*-*

BUILD_DEFS+=		VARBASE

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${PKGMANDIR}/cat1
INSTALLATION_DIRS+=	${PKGMANDIR}/man1
OWN_DIRS+=		${VARBASE}/spool/obex

RCD_SCRIPTS+=		obexapp

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	Makefile
SUBST_STAGE.paths=	post-configure
SUBST_SED.paths+=	-e "s|/usr/local/man|${PREFIX}|"
SUBST_SED.paths+=	-e "s|/usr/local|${PREFIX}|"
SUBST_SED.paths+=	-e "s|/var|${VARBASE}|"

USE_BSD_MAKEFILE=	yes

.include "../../mk/bsd.prefs.mk"

# This uses the older ServiceDiscovery API
.if ${OPSYS} == "NetBSD" && ${OPSYS_VERSION} >= 059900
MAKE_ENV+=	HAVE_LIBSDP=no
RCD_SDPD=	bluetooth
.endif

FILES_SUBST+=	RCD_SDPD=${RCD_SDPD:Usdpd}

# because the directory name conflicts with the rc.d script
post-extract:
	mv ${WRKDIR}/obexapp ${WRKDIR}/${DISTNAME}

.include "../../comms/openobex/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/readline.buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
