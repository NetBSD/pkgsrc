# $NetBSD: Makefile,v 1.1.1.1 2002/03/02 02:51:02 rxg Exp $

DISTNAME=	mp32ogg-0.11
CATEGORIES=	audio perl5
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	# empty

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://faceprint.com/software.phtml
COMMENT=	Convert MP3 files to Ogg Vorbis files

DEPENDS+=	mpg123>=0.59.18:../../audio/mpg123
DEPENDS+=	vorbis-tools>=1.0.0.7:../../audio/vorbis-tools
DEPENDS+=	p5-MP3-Info>=1.00:../../audio/p5-MP3-Info
DEPENDS+=	p5-String-ShellQuote>=1.00:../../textproc/p5-String-ShellQuote

USE_PERL5=	yes

EXTRACT_ONLY=	# empty
WRKSRC=		${WRKDIR}
NO_BUILD=	yes

do-extract:
	${CP} ${_DISTDIR}/${DISTNAME} ${WRKSRC}

post-patch:
	${SED} -e 's:/usr/bin:'${PREFIX}/bin':g' < ${WRKSRC}/${DISTNAME} > ${WRKSRC}/mp32ogg

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mp32ogg ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
