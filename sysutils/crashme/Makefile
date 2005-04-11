# $NetBSD: Makefile,v 1.15 2005/04/11 21:47:23 tv Exp $
#

DISTNAME=       	crashme-2.4
CATEGORIES=		sysutils
MASTER_SITES=   	http://ochimizu-www.jaist.ac.jp:8000/linux/vger/crashme/
EXTRACT_SUFX=		-shar

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		http://people.delphi.com/gjc/crashme.html
COMMENT=		Try to crash machine with random arguments to random system calls

PKG_INSTALLATION_TYPES=	overwrite pkgviews

EXTRACT_CMD=		${EXTRACT_CMD.shar}
MAKEFILE=		makefile
WRKSRC=			${WRKDIR}

.include "../../mk/bsd.pkg.mk"
