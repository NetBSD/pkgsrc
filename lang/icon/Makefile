# $NetBSD: Makefile,v 1.14 1999/07/07 21:25:42 tron Exp $
# FreeBSD Id: Makefile,v 1.8 1997/02/12 08:39:15 tg Exp
#

DISTNAME=       	unix
PKGNAME=		icon-9.3.1
CATEGORIES=		lang
MASTER_SITES=		http://www.cs.arizona.edu/icon/ftp/packages/unix/
EXTRACT_SUFX=		.tgz

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.cs.arizona.edu/icon/index.htm

ONLY_FOR_PLATFORM=	NetBSD-*-alpha NetBSD-*-i386

DIST_SUBDIR=		icon
NO_WRKSUBDIR=		true
ALL_TARGET=		Icon Icon-iconc

MANCOMPRESSED_IF_MANZ=	yes

.include "../../mk/bsd.pkg.mk"
