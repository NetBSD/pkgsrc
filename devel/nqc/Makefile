# $NetBSD: Makefile,v 1.15 2025/11/17 11:00:37 wiz Exp $
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

.include "../../mk/bsd.pkg.mk"
