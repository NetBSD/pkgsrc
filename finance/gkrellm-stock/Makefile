# $NetBSD: Makefile,v 1.5 2003/05/03 22:11:00 wiz Exp $

DISTNAME=	gkrellstock-0.2
PKGNAME=	gkrellm-stock-0.2
PKGREVISION=	2
WRKSRC=		${WRKDIR}/gkrellStock-0.2
CATEGORIES=	finance
MASTER_SITES=	http://www.geocities.com/m_muthukumar/

MAINTAINER=	damon@netbsd.org
HOMEPAGE=	http://www.geocities.com/m_muthukumar/gkrellstock.html
COMMENT=	gkrellm stock ticker plugin

DEPENDS+=       p5-finance-quote-1.*:../../finance/p5-finance-quote

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
