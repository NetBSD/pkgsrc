# $NetBSD: Makefile,v 1.1.1.1 2001/03/15 15:26:35 wiz Exp $
#

DISTNAME=	igerman98-20001109
PKGNAME=	ispell-german-20001109
CATEGORIES=	textproc
MASTER_SITES=	http://www.suse.de/~bjacke/igerman98/dict/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.suse.de/~bjacke/igerman98/
COMMENT=	German dictionary for interactive spelling checker

DEPENDS+=	ispell-base>=3.1.20nb1:../../textproc/ispell-base

ALL_TARGET=	german.hash

.include "../../mk/bsd.pkg.mk"
