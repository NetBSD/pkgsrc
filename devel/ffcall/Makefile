# $NetBSD: Makefile,v 1.17 2004/05/03 16:33:45 jmmv Exp $
#

DISTNAME=	ffcall-1.9
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNUSTEP:=libs/} \
		ftp://ftp.santafe.edu/pub/gnu/ \
		http://www.haible.de/bruno/gnu/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.haible.de/bruno/packages-ffcall.html
COMMENT=	Foreign function call libraries

# the file ${WRKSRC}/avcall/avcall-${MACHINE_ARCH}.c needs to
# be added for additional port support.
ONLY_FOR_PLATFORM=	*-*-alpha *-*-arm *-*-convex *-*-hppa *-*-i386 \
			*-*-ia64 *-*-m68k *-*-m88k *-*-mips *-*-mips64 \
			*-*-mipsn32 *-*-rs6000 *-*-powerpc *-*-s390 \
			*-*-sparc *-*-sparc64 *-*-x86_64

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
