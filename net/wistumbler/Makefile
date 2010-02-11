# $NetBSD: Makefile,v 1.22 2010/02/11 23:12:21 joerg Exp $

DISTNAME=	wistumbler-20020816
PKGNAME=	wistumbler-20020816.0
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://gongon.com/persons/iseki/wistumbler/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gongon.com/persons/iseki/wistumbler/
COMMENT=	Network stumbler for WaveLAN/IEEE wireless networking

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/wistumbler

NOT_FOR_PLATFORM=	NetBSD-0.*-* NetBSD-1.[01234]*-* NetBSD-1.5-*
NOT_FOR_PLATFORM+=	NetBSD-1.5.*-* NetBSD-1.5[A-V]-*
NOT_FOR_PLATFORM+=	Interix-*-*

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wistumbler ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/wistumbler.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
