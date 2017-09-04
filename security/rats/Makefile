# $NetBSD: Makefile,v 1.28 2017/09/04 18:55:09 wiz Exp $
#

DISTNAME=		rats-2.1
PKGREVISION=		5
CATEGORIES=		security
MASTER_SITES+=		https://code.google.com/archive/p/rough-auditing-tool-for-security/downloads/

MAINTAINER=		tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=		https://code.google.com/archive/p/rough-auditing-tool-for-security/
COMMENT=		Rough Auditing Tool for Security
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/rats
BUILD_TARGET=		rats

.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
