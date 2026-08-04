# $NetBSD: Makefile,v 1.25 2026/08/04 20:29:15 wiz Exp $

DISTNAME=	validns-0.8
PKGREVISION=	7
CATEGORIES=	security
MASTER_SITES=	http://www.validns.net/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.validns.net/
COMMENT=	Validns, a high performance DNS/DNSSEC zone validator
LICENSE=	2-clause-bsd

# Depends on perl for make tests

#TOOL_DEPENDS+=	p5-Test-Command-Simple-[0-9]*:../../devel/p5-Test-Command-Simple

#USE_TOOLS+=	perl

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

MAKE_ENV.SunOS+=	EXTRALIBS="-lsocket -lnsl"

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}

#post-build:
#	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} test

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/validns ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/validns.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../devel/libjudy/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
