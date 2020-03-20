# $NetBSD: Makefile,v 1.7 2020/03/20 11:57:24 nia Exp $
#

VERS=		2.3.6

DISTNAME=	primer3-src-${VERS}
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	biology
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=primer3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://primer3.sourceforge.net/
COMMENT=	Design PCR primers
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGNAME}
USE_LANGUAGES=	c c++03
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
	${INSTALL_PROGRAM} ${WRKSRC}/src/${f} ${DESTDIR}${BINDIR}
.endfor
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
