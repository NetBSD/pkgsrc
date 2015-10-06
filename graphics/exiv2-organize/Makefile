# $NetBSD: Makefile,v 1.27.4.1 2015/10/06 17:44:21 spz Exp $

.include "../../graphics/exiv2/Makefile.common"

PKGNAME=	${DISTNAME:S/exiv2/exiv2-organize/}

USE_TOOLS+=		pkg-config
BUILD_DIRS=		contrib/organize
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/contrib/organize/organize \
		${DESTDIR}${PREFIX}/bin/exiv2-organize

.include "../../mk/compiler.mk"
# GCC 4.4 and above needs this
.if !empty(PKGSRC_COMPILER:Mgcc) && !empty(CC_VERSION:Mgcc-4.[4-9]*)
_WRAP_EXTRA_ARGS.CXX+=	-std=c++0x
CWRAPPERS_APPEND.cxx+=	-std=c++0x
.elif !empty(PKGSRC_COMPILER:Mclang)
_WRAP_EXTRA_ARGS.CXX+=	-std=c++11
CWRAPPERS_APPEND.cxx+=	-std=c++11
.endif

.include "../../graphics/exiv2/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
