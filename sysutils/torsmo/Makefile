# $NetBSD: Makefile,v 1.1.1.1 2006/03/29 21:42:55 ghen Exp $

DISTNAME=	torsmo-0.18
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=torsmo/}

MAINTAINER=	ghen@NetBSD.org
HOMEPAGE=	http://torsmo.sourceforge.net/
COMMENT=	Tyopoytaorvelo System Monitor

GNU_CONFIGURE=	yes

EGDIR=		${PREFIX}/share/examples/torsmo
DOCDIR=		${PREFIX}/share/doc/torsmo

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "NetBSD" || ${OPSYS} == "DragonFly" || ${OPSYS} == "FreeBSD" \
			  || ${OPSYS} == "OpenBSD" || ${OPSYS} == "Linux")
SPECIAL_PERMS+=	bin/torsmo ${ROOT_USER} kmem 2555
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/torsmo ${PREFIX:Q}/bin/
	${INSTALL_MAN} ${WRKSRC:Q}/torsmo.1 ${PREFIX:Q}/${PKGMANDIR:Q}/man1/
	${INSTALL_DATA_DIR} ${EGDIR:Q}
	${INSTALL_DATA} ${WRKSRC:Q}/torsmorc.sample ${EGDIR:Q}/
	${INSTALL_DATA_DIR} ${DOCDIR:Q}
	${INSTALL_DATA} ${WRKSRC:Q}/README ${DOCDIR:Q}/
	${INSTALL_DATA} ${WRKSRC:Q}/readme.html ${DOCDIR:Q}/

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
