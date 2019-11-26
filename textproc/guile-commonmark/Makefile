# $NetBSD: Makefile,v 1.1 2019/11/26 16:52:25 ng0 Exp $

DISTNAME=		guile-commonmark-0.1.2
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_GITHUB:=OrangeShark/}
GITHUB_RELEASE=		v0.1.2

MAINTAINER=		ng0@NetBSD.org
HOMEPAGE=		https://github.com/OrangeShark/guile-commonmark/
COMMENT=		Implementation of CommonMark for Guile
LICENSE=		gnu-lgpl-v3
USE_TOOLS+=		pkg-config

GNU_CONFIGURE=		yes

.include "../../lang/guile22/module.mk"
.include "../../mk/bsd.pkg.mk"
