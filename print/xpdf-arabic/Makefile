# $NetBSD: Makefile,v 1.13 2006/02/05 23:10:41 joerg Exp $
#

DISTNAME=	xpdf-arabic-2003-feb-16
PKGNAME=	xpdf-arabic-20030216
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/ \
		http://gd.tuwien.ac.at/publishing/xpdf/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.foolabs.com/xpdf/
COMMENT=	Xpdf support files for Arabic

DEPENDS+=	xpdf>=2.02:../../print/xpdf


WRKSRC=		${WRKDIR}/xpdf-arabic
NO_CONFIGURE=	yes
NO_BUILD=	yes

DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL

post-patch:
	${MV} ${WRKSRC}/add-to-xpdfrc ${WRKSRC}/add-to-xpdfrc.orig
	${SED} -e 's:/usr/local:'${PREFIX}':g' < ${WRKSRC}/add-to-xpdfrc.orig > ${WRKSRC}/add-to-xpdfrc

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/xpdf/arabic
	${INSTALL_DATA} ${WRKSRC}/ISO-8859-6.unicodeMap \
		${PREFIX}/share/xpdf/arabic

post-install:
	${CAT} ${WRKSRC}/add-to-xpdfrc >> ${PKG_SYSCONFDIR}/xpdfrc

.include "../../mk/bsd.pkg.mk"
