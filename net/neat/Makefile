# $NetBSD: Makefile,v 1.1.1.1 2001/05/14 18:05:12 rh Exp $
#

DISTNAME=	neatv4.6
PKGNAME=	${DISTNAME:S/v/-/}
WRKSRC=		${WRKDIR}/neat4
CATEGORIES=	net
MASTER_SITES=	ftp://netsaint.sourceforge.net/pub/netsaint/contrib/addons/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.netsaint.org/
COMMENT=	Netsaint Easy Administration Tool

DEPENDS+=	netsaint-base>=0.0.6:../../net/netsaint-base

USE_PERL5=	YES
NO_BUILD=	YES

do-configure:
.for FILE in neat.cgi neat4.options
	${CP} ${WRKSRC}/${FILE} ${WRKSRC}/${FILE}.old
	${SED} -e 's|/usr/bin/perl|${PREFIX}/bin/perl|g'		\
	    -e 's|/usr/local/netsaint/bin|${PREFIX}/bin|g'		\
	    -e 's|/usr/local/netsaint/etc|${PREFIX}/etc/netsaint|g'	\
	    -e 's|/usr/local/netsaint/neat4/neat4.options|${PREFIX}/etc/neat4.options|g' \
	    -e 's|/usr/local/netsaint/neat4|${PREFIX}/share/netsaint/neat4|g' \
	    < ${WRKSRC}/${FILE}.old > ${WRKSRC}/${FILE}
.endfor

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/netsaint/neat4
	${INSTALL_DATA} ${WRKSRC}/0.6_entity_defs ${PREFIX}/share/netsaint/neat4/entity_defs
.for FILE in 0.7_entity_defs deletion_rules ver_tags
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${PREFIX}/share/netsaint/neat4
.endfor
	${INSTALL_DATA} ${WRKSRC}/neat4.options ${PREFIX}/etc/neat4.options.sample
	${INSTALL_SCRIPT} ${WRKSRC}/neat.cgi ${PREFIX}/libexec/netsaint/cgi-bin
	${INSTALL_DATA} ${WRKSRC}/adminbar.gif ${PREFIX}/share/netsaint/images
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/neat4
.for FILE in GPL README.txt revision_history
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${PREFIX}/share/doc/neat4
.endfor

.include "../../mk/bsd.pkg.mk"
