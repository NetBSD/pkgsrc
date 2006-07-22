# $NetBSD: Makefile,v 1.4 2006/07/22 04:46:15 rillig Exp $

DISTNAME=		gsoap_2.7.7
PKGNAME=		gsoap-2.7.7
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gsoap2/}

MAINTAINER=		chriswareham@chriswareham.demon.co.uk
HOMEPAGE=		http://gsoap2.sourceforge.net/
COMMENT=		Tools for coding SOAP XML Web Services in C and C++

WRKSRC=			${WRKDIR}/gsoap-2.7
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		yacc

PKGCONFIG_OVERRIDE+=	${WRKSRC}/gsoap++.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gsoap.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gsoapck++.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gsoapck.pc.in

.include "../../mk/bsd.pkg.mk"
