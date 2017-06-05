# $NetBSD: Makefile,v 1.2 2017/06/05 14:22:33 ryoon Exp $
#

DISTNAME=		go-sys-0.0.20170427
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=golang/}
GITHUB_PROJECT=		sys
GITHUB_TAG=		9ccfe848b9

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://golang.org/
COMMENT=		Go packages for low-level interaction with the OS
LICENSE=		modified-bsd

GO_SRCPATH=		golang.org/x/sys
GO_DIST_BASE=		${GITHUB_PROJECT}-${GITHUB_TAG}*

USE_TOOLS+=		bash:run

REPLACE_BASH+=		plan9/*.sh unix/*.sh
REPLACE_PERL+=		plan9/*.pl unix/*.pl unix/linux/*.pl

.include "../../lang/go/go-package.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
