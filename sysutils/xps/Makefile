# $NetBSD: Makefile,v 1.35 2007/01/11 11:07:16 joerg Exp $

DISTNAME=	xps-4.2
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=motif-pstree/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://motif-pstree.sourceforge.net/
COMMENT=	Displays the Unix process list as a hierarchical tree

USE_TOOLS+=		gmake perl
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	x_applibdir=${PREFIX}/lib/X11/app-defaults

post-extract:
	${LN} -s FreeBSD ${WRKSRC}/src/DragonFly

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
