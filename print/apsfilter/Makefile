# $NetBSD: Makefile,v 1.2 2001/09/27 23:18:35 jlam Exp $
#

DISTNAME=	apsfilter-6.1.1
CATEGORIES=	print
MASTER_SITES=	http://www.apsfilter.org/download/

MAINTAINER=	zuntum@netbsd.org,jmcneill@invisible.yi.org
HOMEPAGE=	http://www.apsfilter.org/
COMMENT=	number one magic filter for printing under Unix environment

DEPENDS=	recode-[0-9]*:../../converters/recode
DEPENDS+=	ghostscript>=6.01:../../print/ghostscript
#DEPENDS+=	html2ps-[0-9]*:../../print/html2ps
DEPENDS+=	transfig-[0-9]*:../../print/transfig
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	netpbm-[0-9]*:../../graphics/netpbm
DEPENDS+=	a2ps-[0-9]*:../../print/a2ps
DEPENDS+=	psutils-[0-9]*:../../print/psutils

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
