# $NetBSD: Makefile,v 1.1.1.1 2004/02/24 23:03:52 cube Exp $

DISTNAME=	gkrellstock-0.2
PKGNAME=	gkrellm-stock-0.2
PKGREVISION=	4
CATEGORIES=	finance
MASTER_SITES=	http://www.geocities.com/m_muthukumar/

MAINTAINER=	damon@NetBSD.org
HOMEPAGE=	http://www.geocities.com/m_muthukumar/gkrellstock.html
COMMENT=	gkrellm stock ticker plugin

DEPENDS+=       p5-finance-quote-1.*:../../finance/p5-finance-quote

WRKSRC=		${WRKDIR}/gkrellStock-0.2
USE_BUILDLINK2=	# defined
USE_PERL5=	# defined

do-configure:
.for FILE in GetQuote Asia.pm
	${CP} ${WRKSRC}/${FILE} ${WRKSRC}/${FILE}.ORIG
	${SED} -e "s,/usr/bin/perl,${PERL5},g" \
		< ${WRKSRC}/${FILE}.ORIG > ${WRKSRC}/${FILE}
.endfor

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm/plugins

.include "../../sysutils/gkrellm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
