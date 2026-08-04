# $NetBSD: Makefile,v 1.18 2026/08/04 20:29:16 wiz Exp $

DISTNAME=	extipl-5.04
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_OSDN:=extipl/2166/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
#HOMEPAGE=	http://osdn.jp/projects/extipl/
COMMENT=	IPL compatible OS boot selector
LICENSE=	gnu-gpl-v2

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX} \
			MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}

ONLY_FOR_PLATFORM+=	*-*-i386 *-*-x86_64

TOOL_DEPENDS+=		nasm-[0-9]*:../../devel/nasm

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}/src
USE_TOOLS+=	gmake

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
