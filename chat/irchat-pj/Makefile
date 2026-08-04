# $NetBSD: Makefile,v 1.25 2026/08/04 20:28:46 wiz Exp $

DISTNAME=	irchat-pj-2.4.24.22
PKGNAME=	${EMACS_PKGNAME_PREFIX}${DISTNAME}
PKGREVISION=	5
CATEGORIES=	chat
MASTER_SITES=	http://his.luky.org/ftp/mirrors/irchat-pj/
#MASTER_SITES+=	http://gouketsu.net/irchat-pj/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg-ja@jp.NetBSD.org
#HOMEPAGE=	http://gouketsu.net/irchat-pj/
COMMENT=	Emacs lisp interface to Internet Relay Chat

INSTALLATION_DIRS=	bin ${EMACS_LISPPREFIX:C|^${PREFIX}/||}/irchat-pj

CFLAGS+=	-Wno-implicit-function-declaration
CFLAGS+=	-Wno-builtin-declaration-mismatch

.include "../../editors/emacs/modules.mk"

.if ${EMACS_FLAVOR} == "emacs"
INSTALL_TARGET=		install
.elif ${EMACS_FLAVOR} == "xemacs"
BUILD_TARGET=		package
INSTALL_TARGET=		install-package
.else
PKG_FAIL_REASON+=	"Unknown Emacs flavor"
.endif

LIBS.SunOS+=	-lnsl -lsocket
MAKE_ENV+=	LIBS=${LIBS:M*:Q}

do-install:
	cd ${WRKSRC}; \
	${INSTALL_PROGRAM} dcc/dcc ${DESTDIR}${PREFIX}/bin; \
	for f in irchat*.el*; do \
		${INSTALL_DATA} $$f ${DESTDIR}${EMACS_LISPPREFIX}/irchat-pj; \
	done

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
