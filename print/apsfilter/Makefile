# $NetBSD: Makefile,v 1.1.1.1 2001/06/11 21:57:23 zuntum Exp $
#

DISTNAME=	apsfilter-6.1.1
CATEGORIES=	print
MASTER_SITES=	http://www.apsfilter.org/download/

MAINTAINER=	zuntum@netbsd.org,jmcneill@invisible.yi.org
HOMEPAGE=	http://www.apsfilter.org/
COMMENT=	number one magic filter for printing under Unix environment

DEPENDS=	recode-*:../../converters/recode
DEPENDS+=	ghostscript>=6.01:../../print/ghostscript
#DEPENDS+=	html2ps-*:../../print/html2ps
DEPENDS+=	transfig-*:../../print/transfig
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	netpbm-*:../../graphics/netpbm
DEPENDS+=	a2ps-*:../../print/a2ps
DEPENDS+=	psutils-*:../../print/psutils

DEINSTALL_FILE=	${WRKDIR}/.DEINSTALL

WRKSRC=		${WRKDIR}/apsfilter

USE_BZIP2=	YES

post-patch:
	for i in bin/apsfilter SETUP tools/prtmgmt; do				\
		${SED} "s,/usr/local,${LOCALBASE},g" ${WRKSRC}/$$i		\
			> ${WRKSRC}/$$i.done;					\
		${MV} ${WRKSRC}/$$i.done ${WRKSRC}/$$i;				\
	done

	${SED} "s,@LOCALBASE@,${LOCALBASE},g" ${PKGDIR}/DEINSTALL		\
		> ${DEINSTALL_FILE}

.include "../../mk/bsd.pkg.mk"
