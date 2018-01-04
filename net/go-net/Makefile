# $NetBSD: Makefile,v 1.17.6.1 2018/01/04 21:13:18 spz Exp $

DISTNAME=		go-net-20170308
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GITHUB:=golang/}
GITHUB_PROJECT=		net
GITHUB_TAG=		a6577fa

MAINTAINER=		bsiegert@NetBSD.org
HOMEPAGE=		http://golang.org/
COMMENT=		Supplementary network libraries for Go
LICENSE=		modified-bsd

GO_SRCPATH=		golang.org/x/net
GO_DIST_BASE=		${GITHUB_PROJECT}-${GITHUB_TAG}*

CHECK_RELRO_SKIP+=	bin/h2i

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	h2i route

.if ${OPSYS} == "SunOS"
# route support is not yet implemented for sunos
# h2i is missing terminal.MakeRaw and terminal.Restore
.elif ${OPSYS} == "Linux"
PLIST.h2i=	yes
.else
PLIST.h2i=	yes
PLIST.route=	yes
.endif

.include "../../textproc/go-text/buildlink3.mk"
.include "../../security/go-crypto/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
