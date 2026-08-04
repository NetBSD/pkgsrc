# $NetBSD: Makefile,v 1.80 2026/08/04 20:28:53 wiz Exp $
#

DISTNAME=		gice-0.6.2
PKGREVISION=		49
CATEGORIES=		editors
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gice/}
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://gice.sourceforge.net/
COMMENT=		Powerful C text editor with advanced features

WRKSRC=			${WRKDIR}/gice
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		YES

BUILD_TARGET=		gice
INSTALLATION_DIRS=	bin

.include "../../x11/gtk2/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gice ${DESTDIR}${PREFIX}/bin

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
