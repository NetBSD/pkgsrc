# $NetBSD: Makefile,v 1.4 2007/06/15 18:15:21 jlam Exp $

DISTNAME=	torsmo-0.18
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=torsmo/}

MAINTAINER=	ghen@NetBSD.org
HOMEPAGE=	http://torsmo.sourceforge.net/
COMMENT=	Tyopoytaorvelo System Monitor

NOT_FOR_PLATFORM=	Darwin-*-*

GNU_CONFIGURE=	yes

EGDIR=		${PREFIX}/share/examples/torsmo
DOCDIR=		${PREFIX}/share/doc/torsmo

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "NetBSD" || ${OPSYS} == "DragonFly" || ${OPSYS} == "FreeBSD" \
			  || ${OPSYS} == "OpenBSD" || ${OPSYS} == "Linux")
SPECIAL_PERMS+=	bin/torsmo ${BINOWN} kmem 2555
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC:Q}/torsmo ${PREFIX:Q}/bin/
	${INSTALL_MAN} ${WRKSRC:Q}/torsmo.1 ${PREFIX:Q}/${PKGMANDIR:Q}/man1/
	${INSTALL_DATA_DIR} ${EGDIR:Q}
	${INSTALL_DATA} ${WRKSRC:Q}/torsmorc.sample ${EGDIR:Q}/
	${INSTALL_DATA_DIR} ${DOCDIR:Q}
	${INSTALL_DATA} ${WRKSRC:Q}/README ${DOCDIR:Q}/
	${INSTALL_DATA} ${WRKSRC:Q}/readme.html ${DOCDIR:Q}/

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
