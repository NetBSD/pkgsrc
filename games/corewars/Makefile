# $NetBSD: Makefile,v 1.19 2007/12/22 01:48:55 joerg Exp $

DISTNAME=	corewars-0.9.13
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=corewars/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://sal.math.ualberta.ca/
COMMENT=	Programs on a virtual machine, fighting each other

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
MAKE_FLAGS+=	corewars_cmd_LDFLAGS=-largp
.endif

.include "../../devel/argp/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
