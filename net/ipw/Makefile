# $NetBSD: Makefile,v 1.9 2005/12/05 20:50:46 rillig Exp $
#

DISTNAME=	ipw-3.3a
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER= 	mipam@ibb.net,zuntum@NetBSD.org
HOMEPAGE=	http://mjhb.marina-del-rey.ca.us/ipw/
COMMENT= 	"whois" replacement that automatically queries several databases

WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	bin share/doc

LIBS.SunOS+=	-lnsl -lsocket
MAKE_ENV+=	LIBS=${LIBS:M*:Q}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ipw ${PREFIX}/bin
	${INSTALL_DATA} ${FILESDIR}/README ${PREFIX}/share/doc/ipw.README

.include "../../mk/bsd.pkg.mk"
