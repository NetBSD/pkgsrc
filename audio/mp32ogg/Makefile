# $NetBSD: Makefile,v 1.8 2005/06/16 06:57:39 jlam Exp $

DISTNAME=	mp32ogg-0.11
PKGREVISION=	2
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	# empty

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://faceprint.com/software.phtml
COMMENT=	Convert MP3 files to Ogg Vorbis files

DEPENDS+=	mpg123>=0.59.18:../../audio/mpg123
DEPENDS+=	vorbis-tools>=1.0.0.7:../../audio/vorbis-tools
DEPENDS+=	p5-MP3-Info>=1.00:../../audio/p5-MP3-Info
DEPENDS+=	p5-String-ShellQuote>=1.00:../../textproc/p5-String-ShellQuote

USE_PERL5=	yes

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	# empty
NO_BUILD=	yes

REPLACE_PERL=	${WRKSRC}/${DISTNAME}

INSTALLATION_DIRS=	bin

do-extract:
	${CP} ${_DISTDIR}/${DISTNAME} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin/mp32ogg

.include "../../mk/bsd.pkg.mk"
