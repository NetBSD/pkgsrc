# $NetBSD: Makefile,v 1.3 2025/09/18 21:51:36 js Exp $

DISTNAME=	wimlib-1.14.4
PKGREVISION=	2
CATEGORIES=	sysutils devel
MASTER_SITES=	https://wimlib.net/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wimlib.net/
COMMENT=	Open source Windows Imaging (WIM) library and tools
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config gmake

REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	/usr/bin/env bash
REPLACE.bash.new=	${PREFIX}/bin/bash
REPLACE_FILES.bash=	programs/mkwinpeimg.in

DEPENDS=		bash>=0:../../shells/bash

.include "../../filesystems/libntfs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
