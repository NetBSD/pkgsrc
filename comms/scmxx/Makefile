# $NetBSD: Makefile,v 1.50 2012/10/03 11:24:44 asau Exp $
#

DISTNAME=		scmxx-0.9.0
PKGREVISION=		1
CATEGORIES=		comms
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=scmxx/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.hendrik-sattler.de/scmxx/
COMMENT=		Data exchange utility for Siemens mobile phones

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake msgfmt
LDFLAGS.SunOS+=		-lintl

INSTALLATION_DIRS+= share/doc/scmxx share/examples/scmxx

post-install:
	${INSTALL_DATA} ${WRKSRC}/docs/doc_sources.txt			\
	    ${DESTDIR}${PREFIX}/share/doc/scmxx
	${INSTALL_DATA} ${WRKSRC}/docs/gsmcharset.txt			\
	    ${DESTDIR}${PREFIX}/share/doc/scmxx
	${INSTALL_DATA} ${WRKSRC}/examples/debian_with_scmxx.bmp	\
	    ${DESTDIR}${PREFIX}/share/examples/scmxx
	${INSTALL_DATA} ${WRKSRC}/examples/sms.txt			\
	    ${DESTDIR}${PREFIX}/share/examples/scmxx
	${INSTALL_DATA} ${WRKSRC}/examples/vCalendar.vcs		\
	    ${DESTDIR}${PREFIX}/share/examples/scmxx
	${INSTALL_DATA} ${WRKSRC}/examples/vCard.vcf			\
	    ${DESTDIR}${PREFIX}/share/examples/scmxx

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgetopt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
