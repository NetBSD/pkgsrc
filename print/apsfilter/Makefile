# $NetBSD: Makefile,v 1.4 2002/02/21 21:28:14 zuntum Exp $
#

DISTNAME=	apsfilter-7.1.1
CATEGORIES=	print
MASTER_SITES=	http://www.apsfilter.org/download/

MAINTAINER=	packages@netbsd.org
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

HAS_CONFIGURE=	YES
USE_BZIP2=	YES

CONFIGURE_ARGS+=--prefix=${LOCALBASE}
CONFIGURE_ARGS+=--with-shell=${SH}

post-patch:
	for i in bin/apsfilter.in SETUP.in tools/prtmgmt; do		\
		${SED} "s,/usr/local,${LOCALBASE},g" ${WRKSRC}/$$i	\
			> ${WRKSRC}/$$i.done;				\
		${MV} ${WRKSRC}/$$i.done ${WRKSRC}/$$i;			\
	done

	${SED} "s,@LOCALBASE@,${LOCALBASE},g" ${PKGDIR}/DEINSTALL	\
		> ${DEINSTALL_FILE}

.include "../../mk/bsd.pkg.mk"
