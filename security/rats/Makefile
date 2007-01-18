# $NetBSD: Makefile,v 1.22 2007/01/18 22:55:19 rillig Exp $
#

DISTNAME=		rats-2.1
PKGREVISION=		5
CATEGORIES=		security
MASTER_SITES=		http://www.securesoftware.com/rats/

MAINTAINER=		tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=		http://www.securesoftware.com/rats/
COMMENT=		Rough Auditing Tool for Security

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/rats
BUILD_TARGET=		rats

.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
