# $NetBSD: Makefile,v 1.16 2008/03/04 06:59:06 jlam Exp $

DISTNAME=	xvier
PKGNAME=	xvier-1.0
PKGREVISION=	4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SUNSITE:=games/strategy/}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=
COMMENT=	Four-in-a-row game

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_IMAKE=	YES
CPPFLAGS.SunOS+=	-D__EXTENSIONS__

INSTALLATION_DIRS+=	bin libexec ${PKGMANDIR}/man6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xvier ${DESTDIR}${PREFIX}/bin/xvier
	${INSTALL_PROGRAM} ${WRKSRC}/xvier_prog \
		${DESTDIR}${PREFIX}/libexec/xvier_prog
	${INSTALL_MAN} ${WRKSRC}/xvier.man \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/xvier.6

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
