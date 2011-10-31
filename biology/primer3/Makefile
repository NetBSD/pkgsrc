# $NetBSD: Makefile,v 1.1.1.1 2011/10/31 21:25:57 brook Exp $
#

VERS=		2.2.3

DISTNAME=	primer3-${VERS}
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=primer3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://primer3.sourceforge.net/
COMMENT=	Design PCR primers
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
BUILD_DIRS=	src
NO_CONFIGURE=	yes

BINFILES+=	long_seq_tm_test ntdpal ntthal oligotm primer3_core
DOCFILES+=	primer3_manual.htm primer3_v1_1_4_default_settings.txt
DOCFILES+=	primer3web_v0_4_0_default_settings.txt example

BINDIR=		${PREFIX}/bin
DOCDIR=		${PREFIX}/share/doc/primer3

INSTALLATION_DIRS+=	${BINDIR} ${DOCDIR}

do-install:
.for f in ${BINFILES}
	${INSTALL_DATA} ${WRKSRC}/src/${f} ${DESTDIR}${BINDIR}
.endfor
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
