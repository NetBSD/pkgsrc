# $NetBSD: Makefile,v 1.17 2005/06/17 04:49:48 jlam Exp $
#

DISTNAME=		rats-2.1
PKGREVISION=		2
CATEGORIES=		security
MASTER_SITES=		http://www.securesw.com/rats/

MAINTAINER=		tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=		http://www.securesw.com/rats/
COMMENT=		Rough Auditing Tool for Security

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/rats
BUILD_TARGET=		rats

.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
