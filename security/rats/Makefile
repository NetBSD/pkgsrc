# $NetBSD: Makefile,v 1.27 2014/12/16 03:12:42 mef Exp $
#

DISTNAME=		rats-2.1
PKGREVISION=		5
CATEGORIES=		security
MASTER_SITES+=		http://code.google.com/p/rough-auditing-tool-for-security/downloads/

MAINTAINER=		tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=		http://code.google.com/p/rough-auditing-tool-for-security/
COMMENT=		Rough Auditing Tool for Security
LICENSE=		gnu-gpl-v2

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/rats
BUILD_TARGET=		rats

.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
