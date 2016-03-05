# $NetBSD: Makefile,v 1.14 2016/03/05 11:28:21 jperkin Exp $

DISTNAME=		gsoap_2.7.17
PKGNAME=		${DISTNAME:S/_/-/}
PKGREVISION=		3
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gsoap2/}
EXTRACT_SUFX=		.zip

MAINTAINER=		chriswareham@chriswareham.demon.co.uk
HOMEPAGE=		http://gsoap2.sourceforge.net/
COMMENT=		Tools for coding SOAP XML Web Services in C and C++

MAKE_JOBS_SAFE=		no

WRKSRC=			${WRKDIR}/gsoap-2.7
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		yacc flex:run gmake pax

PKGCONFIG_OVERRIDE+=	gsoap++.pc.in
PKGCONFIG_OVERRIDE+=	gsoap.pc.in
PKGCONFIG_OVERRIDE+=	gsoapck++.pc.in
PKGCONFIG_OVERRIDE+=	gsoapck.pc.in
PKGCONFIG_OVERRIDE+=	gsoapssl++.pc.in
PKGCONFIG_OVERRIDE+=	gsoapssl.pc.in

INSTALLATION_DIRS=	share/doc/gsoap

post-install:
	cd ${WRKSRC}/gsoap/doc && pax -rw -pp * ${DESTDIR}${PREFIX}/share/doc/gsoap

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
