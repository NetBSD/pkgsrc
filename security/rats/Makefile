# $NetBSD: Makefile,v 1.21 2006/10/04 21:58:14 wiz Exp $
#

DISTNAME=		rats-2.1
PKGREVISION=		4
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
