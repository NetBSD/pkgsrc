# $NetBSD: Makefile,v 1.2 2023/08/14 05:25:24 wiz Exp $

DISTNAME=	pl196x
PKGNAME=	nltk_data-pl196x-20211124
PKGREVISION=	1
CATEGORIES=	textproc
DIST_SUBDIR=	${PKGNAME_NOREV}

HOMEPAGE=	http://www.mimuw.edu.pl/polszczyzna/pl196x/index_en.htm
COMMENT=	NLTK Data - Polish language of the XX century sixties
#LICENSE=	GNU General Public License

TYPE=		corpora
UNPACK=		yes

SUBST_CLASSES+=		python
SUBST_SED.python=	-e "s,/usr/bin/python,${PYTHONBIN},"
SUBST_FILES.python=	splitter.py
SUBST_STAGE.python=	pre-configure
SUBST_MESSAGE.python=	Fixing path to python binary.

.include "../../meta-pkgs/nltk_data/common.mk"
.include "../../mk/bsd.pkg.mk"
