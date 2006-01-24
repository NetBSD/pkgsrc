# $NetBSD: Makefile,v 1.19 2006/01/24 07:32:33 wiz Exp $
#

DISTNAME=		rats-2.1
PKGREVISION=		3
CATEGORIES=		security
MASTER_SITES=		http://www.securesw.com/rats/

MAINTAINER=		tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=		http://www.securesw.com/rats/
COMMENT=		Rough Auditing Tool for Security

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/rats
BUILD_TARGET=		rats

.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
