# $NetBSD: Makefile,v 1.9 2005/12/05 20:50:49 rillig Exp $
#

DISTNAME=	ripe-whois-3.1.1v6
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ripe.net/tools/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${ASCII_DOC} ${PS_DOC}

MAINTAINER=	seb@NetBSD.org
HOMEPAGE=	http://www.ripe.net/ripencc/pub-services/db/
COMMENT=	RIPE very simple and generic whois client

WRKSRC=		${WRKDIR}/whois-3.1.1v6
GNU_CONFIGURE=	YES
USE_TOOLS+=	perl
MAKE_ENV+=	PERL5=${PERL5:Q}
BUILD_DEFS+=	USE_INET6

ASCII_DOC=		ripe-223.txt
PS_DOC=			ripe-223.ps
DOCS=			${ASCII_DOC} ${PS_DOC}
SITES_${ASCII_DOC}=	ftp://ftp.ripe.net/ripe/docs/
SITES_${PS_DOC}=	ftp://ftp.ripe.net/ripe/docs/
EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/ripe-whois
.for __file__ in ${DOCS}
	${INSTALL_DATA} ${DISTDIR}/${__file__} ${PREFIX}/share/doc/ripe-whois
.endfor

.include "../../mk/bsd.pkg.mk"
