# $NetBSD: Makefile,v 1.30 2012/10/03 11:24:42 asau Exp $
#

DISTNAME=	obexapp-1.4.15
PKGREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	http://people.freebsd.org/~emax/obexapp/

MAINTAINER=	plunky@rya-online.net
HOMEPAGE=	http://people.freebsd.org/~emax/obexapp/
COMMENT=	Obex application to transfer objects to mobile equipment
LICENSE=	modified-bsd

ONLY_FOR_PLATFORM=	FreeBSD-*-* NetBSD-[4-9].*-*

BUILD_DEFS+=		VARBASE

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	${PKGMANDIR}/cat1
INSTALLATION_DIRS+=	${PKGMANDIR}/man1
OWN_DIRS+=		${VARBASE}/spool/obex

RCD_SCRIPTS+=		obexapp

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	Makefile obexapp.1 obexapp.h
SUBST_STAGE.paths=	post-configure
SUBST_SED.paths+=	-e "s|/usr/local/man|${PREFIX}|"
SUBST_SED.paths+=	-e "s|/usr/local|${PREFIX}|"
SUBST_SED.paths+=	-e "s|/var|${VARBASE}|"

USE_BSD_MAKEFILE=	yes

.include "../../mk/bsd.prefs.mk"

# This uses the older ServiceDiscovery API
.if (${OPSYS} == "NetBSD" && \
    (!empty(OS_VERSION:M5.99.*) || !empty(OS_VERSION:M[6-9].*)))
MAKE_ENV+=	HAVE_LIBSDP=no
RCD_SDPD=	bluetooth
.endif

FILES_SUBST+=	RCD_SDPD=${RCD_SDPD:Usdpd}

# because the directory name conflicts with the rc.d script
post-extract:
	mv ${WRKDIR}/obexapp ${WRKDIR}/${DISTNAME}

.include "../../comms/openobex/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
