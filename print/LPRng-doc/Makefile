# $NetBSD: Makefile,v 1.1.1.1 2000/12/12 20:12:06 kei Exp $
# FreeBSD Id: Makefile,v 1.5 1998/10/21 00:57:27 steve Exp
#

DISTNAME=	LPRng_DOC-3.6.13
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.astart.com/pub/LPRng/LPRng/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://www.astart.com/LPRng.html

EXTRACT_ONLY=	# empty
NO_PATCH=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/LPRng
	${PAX}	-rzf ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} \
		-s "#^${DISTNAME}/#${PREFIX}/share/doc/LPRng/#" \
		'*.dvi' '*.gif' '*.html' '*.ps' '*.txt'

.include "../../mk/bsd.pkg.mk"
