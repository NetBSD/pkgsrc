# $NetBSD: Makefile,v 1.58 2022/01/09 20:10:34 bsiegert Exp $

DISTNAME=		go-net-20200130
PKGREVISION=		20
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GITHUB:=golang/}
GITHUB_PROJECT=		net
GITHUB_TAG=		1617124

MAINTAINER=		bsiegert@NetBSD.org
HOMEPAGE=		https://golang.org/
COMMENT=		Supplementary network libraries for Go
LICENSE=		modified-bsd

GO_SRCPATH=		golang.org/x/net
GO_DIST_BASE=		${GITHUB_PROJECT}-${GITHUB_TAG}*

CHECK_RELRO_SKIP+=	bin/h2i

.include "../../lang/go/go-vars.mk"
.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	h2i route

.if ${OPSYS} == "SunOS"
# route support is not yet implemented for sunos
PLIST.h2i=	yes
.elif ${OPSYS} == "Linux"
PLIST.h2i=	yes
.else
PLIST.h2i=	yes
PLIST.route=	yes
.endif

pre-patch:
	${RM} -rf ${WRKSRC}/http2/h2demo

.include "../../textproc/go-text/buildlink3.mk"
.include "../../security/go-crypto/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
