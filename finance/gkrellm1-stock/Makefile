# $NetBSD: Makefile,v 1.7 2004/10/03 00:14:41 tv Exp $

DISTNAME=	gkrellstock-0.2
PKGNAME=	gkrellm-stock-0.2
PKGREVISION=	7
CATEGORIES=	finance
MASTER_SITES=	http://www.geocities.com/m_muthukumar/

MAINTAINER=	damon@NetBSD.org
HOMEPAGE=	http://www.geocities.com/m_muthukumar/gkrellstock.html
COMMENT=	gkrellm stock ticker plugin

DEPENDS+=       p5-finance-quote-1.*:../../finance/p5-finance-quote

WRKSRC=		${WRKDIR}/gkrellStock-0.2
USE_BUILDLINK3=	yes
USE_PERL5=	# defined

do-configure:
.for FILE in GetQuote Asia.pm
	${CP} ${WRKSRC}/${FILE} ${WRKSRC}/${FILE}.ORIG
	${SED} -e "s,/usr/bin/perl,${PERL5},g" \
		< ${WRKSRC}/${FILE}.ORIG > ${WRKSRC}/${FILE}
.endfor

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/gkrellm/plugins

.include "../../sysutils/gkrellm1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
