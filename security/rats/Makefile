# $NetBSD: Makefile,v 1.24 2010/02/20 08:25:51 obache Exp $
#

DISTNAME=		rats-2.1
PKGREVISION=		5
CATEGORIES=		security
MASTER_SITES=		http://www.fortifysoftware.com/servlet/downloads/public/

MAINTAINER=		tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=		http://www.fortifysoftware.com/security-resources/rats.jsp
COMMENT=		Rough Auditing Tool for Security
LICENSE=		gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/rats
BUILD_TARGET=		rats

.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
