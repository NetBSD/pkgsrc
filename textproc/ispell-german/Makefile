# $NetBSD: Makefile,v 1.6 2004/01/24 15:13:20 grant Exp $
#

DISTNAME=	igerman98-20021114
PKGNAME=	ispell-german-20021114
CATEGORIES=	textproc
MASTER_SITES=	http://j3e.de/ispell/igerman98/dict/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://j3e.de/ispell/igerman98/
COMMENT=	German dictionary for interactive spelling checker

DEPENDS+=	ispell-base>=3.1.20nb1:../../textproc/ispell-base

ALL_TARGET=	german.hash
USE_GNU_TOOLS+=	make
USE_PERL5=	build
REPLACE_PERL=	bin/dic2iso.pl bin/grepl bin/sq.pl bin/myspellfixprefix.pl \
		bin/clear_affix.pl bin/unsq.pl bin/uniqflag.pl

do-install:
	${INSTALL_DATA} ${WRKSRC}/german.aff ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/german.hash ${PREFIX}/lib
	(cd ${PREFIX}/lib && ${LN} -s german.aff deutsch.aff)
	(cd ${PREFIX}/lib && ${LN} -s german.hash deutsch.hash)

.include "../../mk/bsd.pkg.mk"
