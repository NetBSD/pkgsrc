# $NetBSD: Makefile,v 1.17 2001/02/17 09:07:13 agc Exp $
# FreeBSD Id: Makefile,v 1.8 1997/02/12 08:39:15 tg Exp
#

DISTNAME=       	unix
PKGNAME=		icon-9.3.2
CATEGORIES=		lang
MASTER_SITES=		http://www.cs.arizona.edu/icon/ftp/packages/unix/
EXTRACT_SUFX=		.tgz

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.cs.arizona.edu/icon/index.htm
COMMENT=		The Icon programming language

ONLY_FOR_PLATFORM=	NetBSD-*-alpha NetBSD-*-i386 NetBSD-*-sparc

DIST_SUBDIR=		${PKGNAME}
NO_WRKSUBDIR=		yes
ALL_TARGET=		Icon Icon-iconc

MANCOMPRESSED_IF_MANZ=	yes

.include "../../mk/bsd.pkg.mk"
