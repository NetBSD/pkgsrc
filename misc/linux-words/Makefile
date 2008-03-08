# $NetBSD: Makefile,v 1.2 2008/03/08 13:50:57 reed Exp $

DISTNAME=		linux.words.2
PKGNAME=		linux-words-2
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_SUNSITE:=libs/}

MAINTAINER=		reed@reedmedia.net
#HOMEPAGE=
COMMENT=		English word list

# For other word packages also consider other word lists like
#  aspell's en list like ftp://ftp.gnu.org/gnu/aspell/aspell-en-0.51-0.tar.bz2
#  SCOWL from http://wordlist.sourceforge.net/
#  NetBSD's word list which has around 234964 words

WRKSRC=			${WRKDIR}/usr/dict
NO_CONFIGURE=		yes
NO_BUILD=		yes
USE_LANGUAGES=		# none

INSTALLATION_DIRS=	share/dict share/doc/linux-words

do-install:
	${INSTALL_DATA} ${WRKSRC}/linux.words ${PREFIX}/share/dict/
	${LN} -s linux.words ${PREFIX}/share/dict/words
	${INSTALL_DATA} ${WRKSRC}/README.linux.words \
		${PREFIX}/share/doc/linux-words/
	${INSTALL_DATA} ${WRKSRC}/README2.linux.words \
		${PREFIX}/share/doc/linux-words/

.include "../../mk/bsd.pkg.mk"
