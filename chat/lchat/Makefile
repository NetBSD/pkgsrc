# $NetBSD: Makefile,v 1.3 2026/01/25 16:13:16 vins Exp $

DISTNAME=	lchat-1.0
PKGREVISION=	2
CATEGORIES=	chat
MASTER_SITES=	https://dl.suckless.org/tools/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tools.suckless.org/lchat/
COMMENT=	Line oriented front end for chat programs
LICENSE=	mit

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE        # asprintf()
CFLAGS.SunOS+=	-D__EXTENSIONS__

SUBST_CLASSES+=		pkgsrc
SUBST_STAGE.pkgsrc=	pre-configure
SUBST_FILES.pkgsrc=	config.mk
SUBST_VARS.pkgsrc+=	PREFIX PKGMANDIR
SUBST_MESSAGE.pkgsrc=	Replacing pkgsrc placeholders

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../textproc/libgrapheme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
