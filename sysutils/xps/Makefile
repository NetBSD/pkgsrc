# $NetBSD: Makefile,v 1.38 2012/01/12 15:58:33 hans Exp $

DISTNAME=	xps-4.2
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=motif-pstree/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://motif-pstree.sourceforge.net/
COMMENT=	Displays the Unix process list as a hierarchical tree

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake perl pod2man pod2html
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	x_applibdir=${PREFIX}/lib/X11/app-defaults

post-extract:
	${LN} -s FreeBSD ${WRKSRC}/src/DragonFly

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
