# $NetBSD: Makefile,v 1.2 2001/02/16 14:38:45 wiz Exp $
#

DISTNAME=		nqc_src_2_0_1
PKGNAME=		nqc-2.0.1
CATEGORIES=		devel
MASTER_SITES=		http://www.enteract.com/~dbaum/nqc/release/

MAINTAINER=		nathanw@netbsd.org
HOMEPAGE=		http://www.enteract.com/~dbaum/nqc/index.html
COMMENT=		Development system for the Lego Mindstorms RCX embedded computer

# NQC doesn't include any install target at all.
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/nqc ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
