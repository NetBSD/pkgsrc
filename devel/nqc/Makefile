# $NetBSD: Makefile,v 1.13 2020/03/20 11:57:28 nia Exp $
#

DISTNAME=		nqc-2.3.r1
PKGNAME=		nqc-2.3.1
CATEGORIES=		devel
MASTER_SITES=		http://bricxcc.sourceforge.net/nqc/release/

MAINTAINER=		nathanw@NetBSD.org
HOMEPAGE=		http://bricxcc.sourceforge.net/nqc/
COMMENT=		Development system for the Lego Mindstorms RCX embedded computer

MAKE_JOBS_SAFE=		no

USE_LANGUAGES=		c++03
USE_TOOLS+=		flex yacc

INSTALL_MAKE_FLAGS+=	BINDIR=${DESTDIR}${PREFIX}/bin \
			MANDIR=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
