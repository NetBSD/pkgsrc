# $NetBSD: Makefile,v 1.3 2022/03/14 11:46:28 nikita Exp $

DISTNAME=		guile-commonmark-0.1.2
PKGREVISION=		1
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_GITHUB:=OrangeShark/}
GITHUB_RELEASE=		v0.1.2

MAINTAINER=		nikita@NetBSD.org
HOMEPAGE=		https://github.com/OrangeShark/guile-commonmark/
COMMENT=		Implementation of CommonMark for Guile
LICENSE=		gnu-lgpl-v3
USE_TOOLS+=		pkg-config

GNU_CONFIGURE=		yes

.include "../../lang/guile30/module.mk"
.include "../../mk/bsd.pkg.mk"
