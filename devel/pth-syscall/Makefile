# $NetBSD: Makefile,v 1.3 2002/07/18 11:22:00 agc Exp $
#

DISTNAME=		pth-1.4.1
PKGNAME=		${DISTNAME:C/pth/pth-syscall/}
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=pth/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/pth/pth.html
COMMENT=		GNU Portable Thread library

USE_BUILDLINK_ONLY=	YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
GNU_CONFIGURE=		YES
GNU_CONFIGURE_PREFIX=	${PREFIX}/pth-syscall
CONFIGURE_ARGS+=	--enable-pthread
CONFIGURE_ARGS+=	--enable-syscall-hard
.if (${MACHINE_ARCH} == "i386" && ${CFLAGS:M-O2} == "-O2")
CFLAGS:=		${CFLAGS:S/-O2/-O0/}
.endif

# for PLIST
PTH_MAJOR=		14
PTH_MINOR=		21
PLIST_SUBST+=		PTH_MAJOR=${PTH_MAJOR} PTH_MINOR=${PTH_MINOR}

test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} test | \
		tee ${WRKSRC}/test.log

.include "../../mk/bsd.pkg.mk"
