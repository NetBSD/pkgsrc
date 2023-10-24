# $NetBSD: Makefile,v 1.17 2023/10/24 22:10:11 wiz Exp $

DISTNAME=	geomyidae-v0.69
PKGNAME=	${DISTNAME:S/-v/-/}
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://bitreich.org/releases/geomyidae/

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	gopher://bitreich.org/1/scm/geomyidae
COMMENT=	Gopher daemon
LICENSE=	mit

BUILD_DEFS+=	VARBASE GEOMYIDAE_USER GEOMYIDAE_GROUP GEOMYIDAE_ROOTDIR
FILES_SUBST+=	GEOMYIDAE_USER=${GEOMYIDAE_USER} GEOMYIDAE_GROUP=${GEOMYIDAE_GROUP}
FILES_SUBST+=	GEOMYIDAE_ROOTDIR=${GEOMYIDAE_ROOTDIR}

EGDIR=		${PREFIX}/share/examples/geomyidae
DOCDIR=		${PREFIX}/share/doc/geomyidae

GEOMYIDAE_USER?=	geomyidae
GEOMYIDAE_GROUP?=	nobody
GEOMYIDAE_ROOTDIR?=	${VARBASE}/gopher

PKG_GROUPS=	${GEOMYIDAE_GROUP}
PKG_USERS=	${GEOMYIDAE_USER}:${GEOMYIDAE_GROUP}

OWN_DIRS+=	${GEOMYIDAE_ROOTDIR}
OWN_DIRS+=	${VARBASE}/run/geomyidae

RCD_SCRIPTS=	geomyidae

SUBST_CLASSES+=		rootdir
SUBST_MESSAGE.rootdir=	Adjust rootdir
SUBST_STAGE.rootdir=	pre-configure
SUBST_FILES.rootdir=	main.c
SUBST_SED.rootdir=	-e 's;/var/gopher;${GEOMYIDAE_ROOTDIR};'

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8 ${EGDIR} ${DOCDIR}

LDFLAGS.SunOS+=		-lsocket -lnsl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/geomyidae ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/geomyidae.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/CGI.md ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/index.gph ${DESTDIR}${EGDIR}

.include "../../security/libretls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
