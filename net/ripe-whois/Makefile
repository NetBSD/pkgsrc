# $NetBSD: Makefile,v 1.2 2002/08/28 14:07:01 seb Exp $
#

DISTNAME=	ripe-whois-3.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ripe.net/tools/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${ASCII_DOC} ${PS_DOC}

MAINTAINER=	seb@netbsd.org
HOMEPAGE=	http://www.ripe.net/ripencc/pub-services/db/
COMMENT=	RIPE very simple and generic whois client

WRKSRC=		${WRKDIR}/whois-3.1
GNU_CONFIGURE=	YES
USE_PERL5=	build
MAKE_ENV+=	PERL5=${PERL5}

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
