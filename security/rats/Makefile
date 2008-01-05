# $NetBSD: Makefile,v 1.23 2008/01/05 05:23:23 obache Exp $
#

DISTNAME=		rats-2.1
PKGREVISION=		5
CATEGORIES=		security
MASTER_SITES=		http://www.fortifysoftware.com/servlet/downloads/public/

MAINTAINER=		tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=		http://www.fortifysoftware.com/security-resources/rats.jsp
COMMENT=		Rough Auditing Tool for Security

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/rats
BUILD_TARGET=		rats

.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
