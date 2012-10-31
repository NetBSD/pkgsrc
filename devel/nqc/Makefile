# $NetBSD: Makefile,v 1.10 2012/10/31 11:17:32 asau Exp $
#

DISTNAME=		nqc-2.3.r1
PKGNAME=		nqc-2.3.1
CATEGORIES=		devel
MASTER_SITES=		http://bricxcc.sourceforge.net/nqc/release/

MAINTAINER=		nathanw@NetBSD.org
HOMEPAGE=		http://bricxcc.sourceforge.net/nqc/
COMMENT=		Development system for the Lego Mindstorms RCX embedded computer

MAKE_JOBS_SAFE=		no

USE_LANGUAGES=		c++
USE_TOOLS+=		flex yacc

INSTALL_MAKE_FLAGS+=	BINDIR=${DESTDIR}${PREFIX}/bin \
			MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
