# $NetBSD: Makefile,v 1.16 2020/03/26 02:27:42 joerg Exp $

DISTNAME=		torsmo-0.18
PKGREVISION=		3
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=torsmo/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://torsmo.sourceforge.net/
COMMENT=		Tyopoytaorvelo System Monitor

BROKEN_ON_PLATFORM=	Darwin-*-*

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-xft
CONFIGURE_ENV+=		XFTCONFIG=pkg-config

EGDIR=			${PREFIX}/share/examples/torsmo
DOCDIR=			${PREFIX}/share/doc/torsmo

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/examples/torsmo
INSTALLATION_DIRS+=	share/doc/torsmo

CHECK_PORTABILITY_SKIP+=	configure.in

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
.include "../../x11/libXft/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
