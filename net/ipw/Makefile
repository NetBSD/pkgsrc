# $NetBSD: Makefile,v 1.5 2003/12/15 17:02:22 agc Exp $
#

DISTNAME=	ipw-3.3a
PKGREVISION=	1
WRKSRC=		${WRKDIR}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER= 	mipam@ibb.net,zuntum@NetBSD.org
HOMEPAGE=	http://mjhb.marina-del-rey.ca.us/ipw/
COMMENT= 	"whois" replacement that automatically queries several databases

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ipw ${PREFIX}/bin
	${INSTALL_DATA} ${FILESDIR}/README ${PREFIX}/share/doc/ipw.README

.include "../../mk/bsd.pkg.mk"
