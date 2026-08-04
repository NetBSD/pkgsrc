# $NetBSD: Makefile,v 1.57 2026/08/04 20:28:43 wiz Exp $

DISTNAME=	dap-2.1.5
PKGREVISION=	9
CATEGORIES=	audio
#MASTER_SITES=	# http://www.cee.hw.ac.uk/~richardk/downloads/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.cee.hw.ac.uk/~richardk/
COMMENT=	Digital audio recording and processing package
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=		no

USE_LANGUAGES=		c c++
INSTALLATION_DIRS+=	bin share/doc/dap
MAKE_FILE=		Makefile.netbsd
MAKE_ENV+=		OTHER_INCLUDE_DIR=.

# Fails with C++14 default language.
FORCE_CXX_STD=		c++03

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/main/DAP ${DESTDIR}${PREFIX}/bin/dap
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/TODO ${WRKSRC}/COPYING \
		${WRKSRC}/FEATURES ${DESTDIR}${PREFIX}/share/doc/dap

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/jpeg.buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/xforms/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
