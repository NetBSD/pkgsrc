# $NetBSD: Makefile,v 1.14 2012/10/02 20:11:48 asau Exp $

DISTNAME=	pcc-1.0.0
CATEGORIES=	lang
MASTER_SITES=	ftp://pcc.ludd.ltu.se/pub/pcc-releases/ \
		http://pcc.ludd.ltu.se/ftp/pub/pcc-releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://pcc.ludd.ltu.se/
COMMENT=	Portable C compiler

ONLY_FOR_PLATFORM=	NetBSD-*-arm* NetBSD-*-i386 NetBSD-*-mips* \
			NetBSD-*-powerpc NetBSD-*-sparc64 NetBSD-*-vax \
			NetBSD-*-x86_64 \
			OpenBSD-*-i386 OpenBSD-*-vax \
			OpenBSD-*-powerpc OpenBSD-*-sparc64 \
			DragonFly-*-i386 \
			MirBSD-*-i386 \
			Darwin-*-i386 Darwin-*-powerpc \
			FreeBSD-*-i386 \
			Linux-*-i386 Linux-*-powerpc

USE_TOOLS+=	lex yacc
# XXX For some reason building with bmake fails randomly.
USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	no

.include "../../mk/bsd.pkg.mk"
