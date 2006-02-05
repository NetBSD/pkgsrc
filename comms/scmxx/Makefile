# $NetBSD: Makefile,v 1.42 2006/02/05 23:08:28 joerg Exp $
#

DISTNAME=		scmxx-0.8.2
PKGREVISION=		1
CATEGORIES=		comms
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=scmxx/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.hendrik-sattler.de/scmxx/
COMMENT=		Data exchange utility for Siemens mobile phones

GNU_CONFIGURE=		yes
USE_MSGFMT_PLURALS=	yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
BUILD_USES_MSGFMT=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/scmxx
	${INSTALL_DATA} ${WRKSRC}/docs/doc_sources.txt			\
	    ${PREFIX}/share/doc/scmxx
	${INSTALL_DATA} ${WRKSRC}/docs/gsmcharset.txt			\
	    ${PREFIX}/share/doc/scmxx
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/scmxx
	${INSTALL_DATA} ${WRKSRC}/examples/debian_with_scmxx.bmp	\
	    ${PREFIX}/share/examples/scmxx
	${INSTALL_DATA} ${WRKSRC}/examples/sms.txt			\
	    ${PREFIX}/share/examples/scmxx
	${INSTALL_DATA} ${WRKSRC}/examples/vCalendar.vcs		\
	    ${PREFIX}/share/examples/scmxx
	${INSTALL_DATA} ${WRKSRC}/examples/vCard.vcf			\
	    ${PREFIX}/share/examples/scmxx

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
