# $NetBSD: Makefile,v 1.8 2026/08/04 20:29:16 wiz Exp $

DISTNAME=	rename-1.3
PKGREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=rename/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rename.sourceforge.net/
COMMENT=	Rename recursively with regex patterns
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rename ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/rename.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
