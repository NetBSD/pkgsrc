# $NetBSD: Makefile,v 1.12 2016/12/10 19:07:20 wiedi Exp $
#

DISTNAME=		go-net-20160910
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GITHUB:=golang/}
GITHUB_PROJECT=		net
GITHUB_TAG=		cfe3c2a752

MAINTAINER=		bsiegert@NetBSD.org
HOMEPAGE=		http://golang.org/
COMMENT=		Supplementary network libraries for Go
LICENSE=		modified-bsd

GO_SRCPATH=		golang.org/x/net
GO_DIST_BASE=		${GITHUB_PROJECT}-${GITHUB_TAG}*

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	notsunos

.if ${OPSYS} != "SunOS"
# route support is not yet implemented for sunos
# h2i is missing terminal.MakeRaw and terminal.Restore
PLIST.notsunos=	yes
.endif

.include "../../textproc/go-text/buildlink3.mk"
.include "../../security/go-crypto/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
