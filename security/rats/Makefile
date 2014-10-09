# $NetBSD: Makefile,v 1.26 2014/10/09 14:06:56 wiz Exp $
#

DISTNAME=		rats-2.1
PKGREVISION=		5
CATEGORIES=		security
MASTER_SITES=		http://www.fortifysoftware.com/servlet/downloads/public/

MAINTAINER=		tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=		http://www.fortifysoftware.com/security-resources/rats.jsp
COMMENT=		Rough Auditing Tool for Security
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/rats
BUILD_TARGET=		rats

.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
