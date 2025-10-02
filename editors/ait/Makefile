# $NetBSD: Makefile,v 1.5 2025/10/02 13:26:29 ktnb Exp $

DISTNAME=	1.13
PKGNAME=	ait-${DISTNAME}
CATEGORIES=	editors
MASTER_SITES=	https://notabug.org/nuclearkev/ait/archive/
DIST_SUBDIR=	ait

MAINTAINER=	ktnb@NetBSD.org
HOMEPAGE=	https://notabug.org/nuclearkev/ait/
COMMENT=	Small but mighty GNU Emacs style editor
LICENSE=	modified-bsd

# termbox doesn't compile on these systems
BROKEN_ON_PLATFORM=	SmartOS-*-*

WRKSRC=		${WRKDIR}/ait
MAKE_FILE=	makefile

INSTALLATION_DIRS+=	bin man/man1

.include "../../mk/bsd.pkg.mk"
