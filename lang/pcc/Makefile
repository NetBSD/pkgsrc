# $NetBSD: Makefile,v 1.17 2020/06/06 21:24:14 rillig Exp $

DISTNAME=	pcc-1.0.0
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	ftp://pcc.ludd.ltu.se/pub/pcc-releases/
MASTER_SITES+=	http://pcc.ludd.ltu.se/ftp/pub/pcc-releases/
EXTRACT_SUFX=	.tgz

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://pcc.ludd.ltu.se/
COMMENT=	Portable C compiler

ONLY_FOR_PLATFORM=	NetBSD-*-arm* NetBSD-*-i386 NetBSD-*-mips* \
			NetBSD-*-powerpc NetBSD-*-sparc64 NetBSD-*-vax \
			NetBSD-*-x86_64 \
			OpenBSD-*-i386 OpenBSD-*-vax \
			OpenBSD-*-powerpc OpenBSD-*-sparc64 \
			MirBSD-*-i386 \
			Darwin-*-i386 Darwin-*-powerpc \
			FreeBSD-*-i386 \
			Linux-*-i386 Linux-*-powerpc

USE_TOOLS+=	lex yacc
GNU_CONFIGURE=	yes

# On NetBSD 8.0 x86_64, pcc-1.0.0 fails with:
# In file included from builtins.c:27:0:
# pass1.h:46:22: fatal error: external.h: No such file or directory
MAKE_JOBS_SAFE=	no

# Do not rely on the timestamps of directories for resolving the
# dependencies in the Makefiles.
#
# Without this, building with bmake sometimes only processes the cc/cc
# directory, which is not enough since then the install phase cannot
# find cpp.
SUBST_CLASSES+=		mk
SUBST_STAGE.mk=		pre-configure
SUBST_FILES.mk=		Makefile.in */Makefile.in
SUBST_SED.mk=		-e 's,: nonexistant$$,: .PHONY,'

.include "../../mk/bsd.pkg.mk"
