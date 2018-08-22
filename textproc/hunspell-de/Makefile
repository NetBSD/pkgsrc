# $NetBSD: Makefile,v 1.22 2018/08/22 09:46:46 wiz Exp $

DISTNAME=	igerman98-20161207
PKGNAME=	${DISTNAME:S/igerman98/hunspell-de/}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	https://www.j3e.de/ispell/igerman98/dict/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.j3e.de/ispell/igerman98/
COMMENT=	German dictionaries for hunspell
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

BUILD_DEPENDS+=	ispell>=3.1.20nb1:../../textproc/ispell
DEPENDS+=	hunspell>=1.1.5:../../textproc/hunspell

USE_LANGUAGES=	# none

BUILD_TARGET=   hunspell-all
USE_TOOLS+=     gmake perl sed
REPLACE_PERL=   bin/clear_affix.pl bin/dic2iso.pl bin/grepl bin/lcfirst.pl \
		bin/sq.pl bin/uniqflag.pl bin/unsq.pl bin/extractlines.pl \
		bin/hunspell-optimize-roothelper.pl bin/myspellfixprefix.pl

SUBST_CLASSES+=		sed
SUBST_FILES.sed=	bin/clear_affix bin/dic2iso bin/iso2dic bin/iso2tex \
			bin/tex2iso bin/conv_dict_de_CH
SUBST_SED.sed=		-e "s,/bin/sed,${SED},"
SUBST_STAGE.sed=	pre-build
SUBST_MESSAGE.sed=	Fixing path to sed.

INSTALLATION_DIRS=	share/hunspell

do-install:
	${INSTALL_DATA} ${WRKSRC}/hunspell/de*aff ${DESTDIR}${PREFIX}/share/hunspell
	${INSTALL_DATA} ${WRKSRC}/hunspell/de*dic ${DESTDIR}${PREFIX}/share/hunspell

.include "../../mk/bsd.pkg.mk"
