# $NetBSD: Makefile,v 1.5 2008/01/04 12:31:02 ghen Exp $

DISTNAME=		torsmo-0.18
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=torsmo/}

MAINTAINER=		ghen@NetBSD.org
HOMEPAGE=		http://torsmo.sourceforge.net/
COMMENT=		Tyopoytaorvelo System Monitor

PKG_DESTDIR_SUPPORT=	user-destdir

NOT_FOR_PLATFORM=	Darwin-*-*

GNU_CONFIGURE=		yes

EGDIR=			${PREFIX}/share/examples/torsmo
DOCDIR=			${PREFIX}/share/doc/torsmo

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/examples/torsmo
INSTALLATION_DIRS+=	share/doc/torsmo

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "NetBSD" || ${OPSYS} == "DragonFly" || ${OPSYS} == "FreeBSD" \
			  || ${OPSYS} == "OpenBSD" || ${OPSYS} == "Linux")
SPECIAL_PERMS+=	bin/torsmo ${BINOWN} kmem 2555
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/torsmo ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/torsmo.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA} ${WRKSRC}/torsmorc.sample ${DESTDIR}${EGDIR}/
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/readme.html ${DESTDIR}${DOCDIR}/

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
