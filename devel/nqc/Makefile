# $NetBSD: Makefile,v 1.16 2026/08/04 20:28:51 wiz Exp $
#

DISTNAME=		nqc-2.3.r1
PKGNAME=		nqc-2.3.1
CATEGORIES=		devel
MASTER_SITES=		http://bricxcc.sourceforge.net/nqc/release/

MAINTAINER=		nathanw@NetBSD.org
HOMEPAGE=		https://bricxcc.sourceforge.net/nqc/
COMMENT=		Development system for the Lego Mindstorms RCX embedded computer

MAKE_JOBS_SAFE=		no

USE_LANGUAGES=		c c++
USE_TOOLS+=		flex yacc

# Fails with C++14 default language
FORCE_CXX_STD=		c++03

INSTALL_MAKE_FLAGS+=	BINDIR=${DESTDIR}${PREFIX}/bin \
			MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
