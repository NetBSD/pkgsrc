# $NetBSD: Makefile,v 1.10 2004/04/24 22:46:11 jlam Exp $
# FreeBSD Id: Makefile,v 1.5 1998/10/21 00:57:27 steve Exp
#

DISTNAME=	LPRng_DOC-3.6.13
PKGNAME=	LPRng-doc-3.6.13
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.astart.com/pub/LPRng/LPRng/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.lprng.com/
COMMENT=	LPRng documentation in dvi, text, html and ps formats

EXTRACT_ONLY=	# empty
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/LPRng
	${PAX} -O -zr -f ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
		-s "#^${DISTNAME}/#${PREFIX}/share/doc/LPRng/#" \
		'*.dvi' '*.gif' '*.html' '*.ps' '*.txt'

.include "../../mk/bsd.pkg.mk"
