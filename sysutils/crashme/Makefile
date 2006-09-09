# $NetBSD: Makefile,v 1.17 2006/09/09 02:46:08 obache Exp $
#

DISTNAME=       	crashme-2.4
CATEGORIES=		sysutils
MASTER_SITES=   	http://ochimizu-www.jaist.ac.jp:8000/linux/vger/crashme/
EXTRACT_SUFX=		-shar

MAINTAINER=		agc@NetBSD.org
HOMEPAGE=		http://people.delphi.com/gjc/crashme.html
COMMENT=		Try to crash machine with random arguments to random system calls

PKG_INSTALLATION_TYPES=	overwrite pkgviews

EXTRACT_OPTS=		-f shar
MAKE_FILE=		makefile
WRKSRC=			${WRKDIR}

.include "../../mk/bsd.pkg.mk"
