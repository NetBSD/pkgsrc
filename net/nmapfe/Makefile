# $NetBSD: Makefile,v 1.1.1.1 2000/05/04 15:30:06 hubertf Exp $

DISTNAME=	nmapfe-0.9.5
CATEGORIES=	net security
MASTER_SITES=	http://codebox.net/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=     reinoud@ibbnet.org
HOMEPAGE=	http://www.insecure.org/nmap/index.html

DEPENDS+=	nmap-2.*:../../net/nmap
DEPENDS+=	gtk+-1.2.*:../../x11/gtk

GNU_CONFIGURE=	Yes
CONFIGURE_ENV+= INSTALL=${INSTALL}

WRKSRC= ${WRKDIR}/nmapfe

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
MAKE_ENV+=      CPPFLAGS=""
.endif

.include "../../mk/bsd.pkg.mk"
