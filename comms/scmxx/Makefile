# $NetBSD: Makefile,v 1.20 2003/04/18 16:18:32 wiz Exp $
#

DISTNAME=		scmxx-0.6.3.7
CATEGORIES=		comms
MASTER_SITES=		http://ma2geo.mathematik.uni-karlsruhe.de/~hendrik/scmxx/download/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		kleink@netbsd.org
HOMEPAGE=		http://www.hendrik-sattler.de/scmxx/
COMMENT=		Data exchange utility for Siemens mobile phones

USE_BUILDLINK2=		yes
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_DIR}

GNU_CONFIGURE=		yes
USE_GMAKE=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/scmxx
	${INSTALL_DATA} ${WRKSRC}/docs/doc_sources.txt			\
	    ${PREFIX}/share/doc/scmxx
	${INSTALL_DATA} ${WRKSRC}/docs/gsmcharset.txt			\
	    ${PREFIX}/share/doc/scmxx
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/scmxx
	${INSTALL_DATA} ${WRKSRC}/examples/phonebook			\
	    ${PREFIX}/share/examples/scmxx
	${INSTALL_DATA} ${WRKSRC}/examples/sms.txt			\
	    ${PREFIX}/share/examples/scmxx
	${INSTALL_DATA} ${WRKSRC}/examples/vCalendar.vcs		\
	    ${PREFIX}/share/examples/scmxx
	${INSTALL_DATA} ${WRKSRC}/examples/vCard.vcf			\
	    ${PREFIX}/share/examples/scmxx

.include "../../converters/libiconv/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
