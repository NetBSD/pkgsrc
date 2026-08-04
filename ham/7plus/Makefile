# $NetBSD: Makefile,v 1.20 2026/08/04 20:29:00 wiz Exp $
#

DISTNAME=	7pl225sr
PKGNAME=	7plus-225
PKGREVISION=	3
CATEGORIES=	ham
MASTER_SITES=	https://www.aydogan.net/distfiles/ham/
DISTFILES=	7pl225sr.tgz \
		7pl210mg.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	#http://home.t-online.de/home/dg1bbq/
COMMENT=	Uuencode-like file coder for AMPR BBS S&F of binary files
# Text talks about restrictions, but doesn't grant permissions under
# copyright law.  Pick generic-nonlicense and potential users can evaluate.
LICENSE=	generic-nonlicense

RESTRICTED=		No clear license, no commercial use
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}

WRKSRC=		${WRKDIR}/7plsrc.225
MAKE_FILE=	netbsd.mak
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin share/doc/7plus

post-install:
	${INSTALL_DATA} ${WRKDIR}/*.txt ${DESTDIR}${PREFIX}/share/doc/7plus && \
	${INSTALL_DATA} ${WRKDIR}/readme.now ${DESTDIR}${PREFIX}/share/doc/7plus

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
