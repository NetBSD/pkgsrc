# $NetBSD: Makefile,v 1.17 2012/10/03 21:57:48 wiz Exp $
#

DISTNAME=	igerman98-20120607
PKGNAME=	ispell-german-20120607
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://j3e.de/ispell/igerman98/dict/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://j3e.de/ispell/igerman98/
COMMENT=	German dictionary for interactive spelling checker

DEPENDS+=	ispell-base>=3.1.20nb1:../../textproc/ispell-base

BUILD_TARGET=	ispell/de_DE.aff ispell/de_DE.hash ispell/de_AT.aff ispell/de_AT.hash ispell/de_CH.aff ispell/de_CH.hash
USE_TOOLS+=	gmake perl
REPLACE_PERL=	bin/dic2iso.pl bin/grepl bin/sq.pl bin/myspellfixprefix.pl \
		bin/clear_affix.pl bin/unsq.pl bin/uniqflag.pl

INSTALLATION_DIRS=	lib
PKG_DESTDIR_SUPPORT=	user-destdir

do-install:
	${INSTALL_DATA} ${WRKSRC}/ispell/*.aff ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/ispell/*.hash ${DESTDIR}${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
