# $NetBSD: Makefile,v 1.14 2006/09/07 21:27:30 dan Exp $

DISTNAME=	mgm-1.1
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://www.xiph.org/mgm/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://linuxmafia.com/mgm/
COMMENT=	Moaning Goat Meter

DEPENDS+=	p5-Tk-[0-9]*:../../x11/p5-Tk

WRKSRC=		${WRKDIR}/mgm
NO_BUILD=	yes
USE_TOOLS+=	perl:run

MGM_PERL_DIR=	${PREFIX}/lib/mgm
MGM_DOC_DIR=	${PREFIX}/share/doc/mgm

INSTALLATION_DIRS=	bin

REPLACE_PERL+=	mgm lib/xpm

post-patch:
	${SED} -e 's|@@MGM_PERL_DIR@@|${MGM_PERL_DIR}|' \
		${FILESDIR}/mgm.sh > ${WRKDIR}/mgm.sh

do-install:
	${INSTALL_DATA_DIR} ${MGM_PERL_DIR} ${MGM_PERL_DIR}/modules
	${INSTALL_SCRIPT} ${WRKSRC}/mgm ${MGM_PERL_DIR}
	set -e; \
	cd ${WRKSRC}; \
	for DIR in lib modules/*; do \
		${INSTALL_DATA_DIR} ${MGM_PERL_DIR}/"$$DIR"; \
		for FILE in "$$DIR"/*; do \
			${INSTALL_DATA} "$$FILE" ${MGM_PERL_DIR}/"$$DIR"; \
		done; \
	done
	${INSTALL_DATA_DIR} ${MGM_DOC_DIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} * ${MGM_DOC_DIR}
	${INSTALL_SCRIPT} ${WRKDIR}/mgm.sh ${PREFIX}/bin/mgm

.include "../../mk/bsd.pkg.mk"
