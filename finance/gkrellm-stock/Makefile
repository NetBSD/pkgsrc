# $NetBSD: Makefile,v 1.1.1.1 2001/10/30 13:23:40 damon Exp $

DISTNAME=	gkrellstock-0.2
PKGNAME=	gkrellm-stock-0.2
WRKSRC=		${WRKDIR}/gkrellStock-0.2
CATEGORIES=	finance
MASTER_SITES=	http://www.geocities.com/m_muthukumar/

MAINTAINER=	damon@netbsd.org
HOMEPAGE=	http://www.geocities.com/m_muthukumar/gkrellstock.html
COMMENT=	gkrellm stock ticker plugin

DEPENDS+=       gkrellm-1.2.*:../../sysutils/gkrellm
DEPENDS+=       p5-finance-quote-1.*:../../finance/p5-finance-quote

USE_PERL5=	# defined

do-configure:
.for FILE in GetQuote Asia.pm
	${CP} ${WRKSRC}/${FILE} ${WRKSRC}/${FILE}.ORIG
	${SED} -e "s,/usr/bin/perl,${PERL5},g" \
		< ${WRKSRC}/${FILE}.ORIG > ${WRKSRC}/${FILE}
.endfor

.include "../../mk/bsd.pkg.mk"
