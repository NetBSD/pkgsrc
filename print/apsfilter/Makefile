# $NetBSD: Makefile,v 1.31 2013/04/24 10:06:51 sbd Exp $
#

DISTNAME=	apsfilter-7.2.6
PKGREVISION=	2
CATEGORIES=	print
MASTER_SITES=	http://www.apsfilter.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.apsfilter.org/
COMMENT=	Flexible magic filter for printing under Unix environment

DEPENDS+=	recode-[0-9]*:../../converters/recode
#DEPENDS+=	html2ps-[0-9]*:../../print/html2ps
DEPENDS+=	transfig-[0-9]*:../../print/transfig
DEPENDS+=	jpeg>=6b:../../graphics/jpeg
DEPENDS+=	netpbm>=9.7nb1:../../graphics/netpbm
DEPENDS+=	a2ps-[0-9]*:../../print/a2ps
DEPENDS+=	psutils-[0-9]*:../../print/psutils

WRKSRC=		${WRKDIR}/apsfilter
HAS_CONFIGURE=	YES
USE_BZIP2=	YES
USE_TOOLS+=	awk gs:run

CONFIGURE_ARGS+=--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=--with-shell=${SH:Q}
CONFIGURE_ARGS+=--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=--with-awk=${TOOLS_AWK:Q}

PKG_SYSCONFSUBDIR?=	apsfilter
CONF_FILES=	${PREFIX}/share/apsfilter/template/apsfilterrc \
		${PKG_SYSCONFDIR}/apsfilterrc

post-patch:
	for i in bin/apsfilter.in SETUP.in tools/prtmgmt; do		\
		${SED} "s,/usr/local,${LOCALBASE},g" ${WRKSRC}/$$i	\
			> ${WRKSRC}/$$i.done;				\
		${MV} ${WRKSRC}/$$i.done ${WRKSRC}/$$i;			\
	done

.include "../../mk/bsd.pkg.mk"
