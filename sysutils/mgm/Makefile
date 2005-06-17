# $NetBSD: Makefile,v 1.8 2005/06/17 03:50:34 jlam Exp $

DISTNAME=	mgm-1.1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.xiph.org/mgm/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.xiph.org/mgm/
COMMENT=	Moaning Goat Meter

DEPENDS+=	p5-Tk-[0-9]*:../../x11/p5-Tk

WRKSRC=		${WRKDIR}/${DISTNAME:C/-.*$//}
NO_BUILD=	# defined
USE_PERL5=	YES
PERL_SCRIPTS=	mgm

MGM_PERL_DIR=	${PREFIX}/lib/${DISTNAME:C/-.*$//}
MGM_DOC_DIR=	${PREFIX}/share/doc/html/${DISTNAME:C/-.*$//}

INSTALLATION_DIRS=	bin

post-patch:
	${SED} -e 's|@@MGM_PERL_DIR@@|${MGM_PERL_DIR}|' \
		${FILESDIR}/mgm.sh > ${WRKDIR}/mgm.sh
	cd ${WRKSRC}; \
	for FILE in ${PERL_SCRIPTS}; do \
		${CP} $$FILE $${FILE}.orig; \
		${SED} -e 's#/usr/bin/perl#${PERL5}#g' \
			<$${FILE}.orig >$$FILE; \
	done

do-install:
	${INSTALL_DATA_DIR} ${MGM_PERL_DIR} ${MGM_PERL_DIR}/modules
	${INSTALL_SCRIPT} ${WRKSRC}/mgm ${MGM_PERL_DIR}
	cd ${WRKSRC}; \
	for DIR in lib modules/*; do \
		${INSTALL_DATA_DIR} ${MGM_PERL_DIR}/$$DIR; \
		for FILE in $$DIR/*; do \
			${INSTALL_DATA} $$FILE ${MGM_PERL_DIR}/$$DIR; \
		done; \
	done
	${INSTALL_DATA_DIR} ${MGM_DOC_DIR}
	for FILE in ${WRKSRC}/doc/*; do \
		${INSTALL_DATA} $$FILE ${MGM_DOC_DIR}; \
	done
	${INSTALL_SCRIPT} ${WRKDIR}/mgm.sh ${PREFIX}/bin/mgm

.include "../../mk/bsd.pkg.mk"
