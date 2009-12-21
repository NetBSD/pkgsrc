# $NetBSD: Makefile,v 1.8 2009/12/21 20:13:36 joerg Exp $

DISTNAME=		gsoap_2.7.13
PKGNAME=		gsoap-2.7.13
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gsoap2/}

MAINTAINER=		chriswareham@chriswareham.demon.co.uk
HOMEPAGE=		http://gsoap2.sourceforge.net/
COMMENT=		Tools for coding SOAP XML Web Services in C and C++

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

WRKSRC=			${WRKDIR}/gsoap-2.7
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		yacc flex gmake

PKGCONFIG_OVERRIDE+=	${WRKSRC}/gsoap++.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gsoap.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gsoapck++.pc.in
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gsoapck.pc.in

.include "../../mk/bsd.pkg.mk"
