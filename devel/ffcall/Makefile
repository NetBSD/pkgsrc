# $NetBSD: Makefile,v 1.20 2004/11/08 14:05:21 wiz Exp $

DISTNAME=	ffcall-1.10
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.santafe.edu/pub/gnu/ \
		http://www.haible.de/bruno/gnu/ \
		${MASTER_SITE_GNUSTEP:=libs/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.haible.de/bruno/packages-ffcall.html
COMMENT=	Foreign function call libraries

# the file ${WRKSRC}/avcall/avcall-${MACHINE_ARCH}.c needs to
# be added for additional port support.
ONLY_FOR_PLATFORM=	*-*-alpha *-*-arm *-*-convex *-*-hppa *-*-i386 \
			*-*-ia64 *-*-m68k *-*-m88k *-*-mips *-*-mipsel \
			*-*-mipseb *-*-mips64 *-*-mipsn32 \
			*-*-powerpc *-*-rs6000 \
			*-*-s390 *-*-sparc *-*-sparc64 \
			*-*-x86_64

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-shared

MAKE_FLAGS+=		htmldir=${PREFIX}/share/doc/ffcall

post-patch:
	${CP} ${FILESDIR}/tramp-rs6000-netbsd.s ${WRKSRC}/callback/trampoline_r
	${CP} ${FILESDIR}/vacall-rs6000-netbsd.s ${WRKSRC}/callback/vacall_r

# Run the supplied tests to sanity check everything
post-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} check

.include "../../mk/bsd.pkg.mk"
