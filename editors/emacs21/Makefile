# $NetBSD: Makefile,v 1.49 2023/10/21 17:10:04 gdt Exp $

PKGREVISION=	47
CATEGORIES=	editors

CONFLICTS+=	emacs21-nox11-[0-9]*

USE_TOOLS+=	imake

MKPIE_SUPPORTED=	no

.include "options.mk"

.include "../../editors/emacs21/Makefile.common"

.include "../../mk/bsd.pkg.mk"
