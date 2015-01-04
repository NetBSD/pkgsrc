# $NetBSD: Makefile,v 1.17 2015/01/04 04:46:01 dholland Exp $
#

DISTNAME=	ald-0.1.7
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ald/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ald.sourceforge.net/
COMMENT=	Very nice x86 assembly-level debugger
LICENSE=	gnu-gpl-v2

# x86-only (no 64-bit support, it seems)
ONLY_FOR_PLATFORM=	*-*-i386

GNU_CONFIGURE=	YES

.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
