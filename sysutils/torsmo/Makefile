# $NetBSD: Makefile,v 1.7 2010/02/19 21:21:20 joerg Exp $

DISTNAME=		torsmo-0.18
PKGREVISION=		1
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

.if ${X11_TYPE} == "modular"
CONFIGURE_ARGS+=	--x-includes=${PREFIX}/include
CONFIGURE_ARGS+=	--x-libraries=${PREFIX}/lib
.endif

.if (${OPSYS} == "NetBSD" || ${OPSYS} == "DragonFly" || ${OPSYS} == "FreeBSD" \
			  || ${OPSYS} == "OpenBSD" || ${OPSYS} == "Linux")
SPECIAL_PERMS+=	bin/torsmo ${REAL_ROOT_USER} kmem 2555
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
