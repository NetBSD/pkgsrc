# $NetBSD: Makefile,v 1.13 2016/09/24 12:38:04 mef Exp $
#

DISTNAME=	asm2html-1.4
CATEGORIES=	devel
MASTER_SITES=	http://virtus.ath.cx/asm2html/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bsdforge.com/projects/textproc/asm2html/
COMMENT=	Tool to convert NASM source files to HTML

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

GNU_CONFIGURE=	YES

MAKE_INSTALL_FLAGS+=	PKGMANDIR=${PKGMANDIR:Q}

.include "../../mk/bsd.pkg.mk"
