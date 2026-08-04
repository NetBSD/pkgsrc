# $NetBSD: Makefile,v 1.44 2026/08/04 20:29:17 wiz Exp $

DISTNAME=	glimpse-4.18.6
CATEGORIES=	textproc databases
MASTER_SITES=	http://webglimpse.net/trial/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://webglimpse.net/
COMMENT=	Text search engine
LICENSE=	isc

# both install bin/agrep (approx. grep)
CONFLICTS+=	tre>=0.7.5nb6

MAKE_JOBS_SAFE=		no

USE_TOOLS+=		gmake flex
GNU_CONFIGURE=		yes
MAKE_FLAGS=		mandir=${PREFIX}/${PKGMANDIR}/man1
INSTALLATION_DIRS=	share/doc/glimpse

post-install:
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DESTDIR}${PREFIX}/share/doc/glimpse
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/glimpse

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
