# $NetBSD: Makefile,v 1.1 2024/05/08 13:48:52 ktnb Exp $

DISTNAME=	ait-1.8-rc4
PKGNAME=	${DISTNAME:S/-rc/rc/}
CATEGORIES=	editors
MASTER_SITES=	https://notabug.org/nuclearkev/ait/archive/

MAINTAINER=	ktnb@NetBSD.org
HOMEPAGE=	https://notabug.org/nuclearkev/ait/
COMMENT=	Small but mighty GNU Emacs style editor
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/ait
MAKE_FILE=	makefile

INSTALLATION_DIRS+=	bin man/man1

.include "../../mk/bsd.pkg.mk"
