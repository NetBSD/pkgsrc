# $NetBSD: Makefile,v 1.29 2023/12/19 23:56:00 gdt Exp $
#
PKGNAME=		jed-0.99.19
LICENSE=		gnu-gpl-v2

.include "../../editors/jed/Makefile.common"
COMMENT=		Extensible folding editor with Emacs/WordStar/EDT emulations

CONFLICTS=		xjed-[0-9]*

CONFIGURE_ARGS+=	--without-X

.include "../../mk/bsd.pkg.mk"
