# $NetBSD: Makefile,v 1.4 2026/08/04 20:29:02 wiz Exp $

.include "../../lang/chicken5/Makefile.common"

PKGNAME=	${DISTNAME:S/chicken/chicken5-boot/}

BUILD_TARGET=		boot-chicken
WRKSRC=			${WRKDIR}/chicken-${PKGVERSION_NOREV}
INSTALLATION_DIRS+=	libexec

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/chicken-boot ${DESTDIR}${PREFIX}/libexec/chicken-bootstrap

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
