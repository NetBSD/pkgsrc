# $NetBSD: Makefile,v 1.17 2005/06/17 04:49:48 jlam Exp $
#

DISTNAME=	apsfilter-7.2.5
CATEGORIES=	print
MASTER_SITES=	http://www.apsfilter.org/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.apsfilter.org/
COMMENT=	Number one magic filter for printing under Unix environment

DEPENDS=	recode-[0-9]*:../../converters/recode
#DEPENDS+=	html2ps-[0-9]*:../../print/html2ps
DEPENDS+=	transfig-[0-9]*:../../print/transfig
DEPENDS+=	jpeg>=6b:../../graphics/jpeg
DEPENDS+=	netpbm>=9.7nb1:../../graphics/netpbm
DEPENDS+=	a2ps-[0-9]*:../../print/a2ps
DEPENDS+=	psutils-[0-9]*:../../print/psutils

WRKSRC=		${WRKDIR}/apsfilter
HAS_CONFIGURE=	YES
USE_BZIP2=	YES
USE_PKGINSTALL=	YES

CONFIGURE_ARGS+=--prefix=${PREFIX}
CONFIGURE_ARGS+=--with-shell=${SH}
CONFIGURE_ARGS+=--sysconfdir=${PKG_SYSCONFDIR}

PKG_SYSCONFSUBDIR?=	apsfilter
CONF_FILES=	${PREFIX}/share/apsfilter/template/apsfilterrc \
		${PKG_SYSCONFDIR}/apsfilterrc

DEINSTALL_EXTRA_TMPL=	${.CURDIR}/INSTALL
INSTALL_EXTRA_TMPL=	${.CURDIR}/INSTALL

post-patch:
	for i in bin/apsfilter.in SETUP.in tools/prtmgmt; do		\
		${SED} "s,/usr/local,${LOCALBASE},g" ${WRKSRC}/$$i	\
			> ${WRKSRC}/$$i.done;				\
		${MV} ${WRKSRC}/$$i.done ${WRKSRC}/$$i;			\
	done

.include "../../mk/ghostscript.mk"
.include "../../mk/bsd.pkg.mk"
