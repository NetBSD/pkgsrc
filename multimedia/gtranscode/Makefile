# $NetBSD: Makefile,v 1.8 2026/08/04 20:29:10 wiz Exp $
#

DISTNAME=	gtranscode-v0.3
PKGNAME=	${DISTNAME:S/v//}
PKGREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://www.fuzzymonkey.net/files/

MAINTAINER=	ccatrian@eml.cc
#HOMEPAGE=	http://fuzzymonkey.net/software/gtranscode/
COMMENT=	GTK+ GUI front-end for transcode

DEPENDS+=	transcode-[0-9]*:../../multimedia/transcode

WRKSRC=		${WRKDIR}/gtranscode

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gtranscode ${DESTDIR}${PREFIX}/bin

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
