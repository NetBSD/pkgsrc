# $NetBSD: Makefile,v 1.3 2003/03/29 12:41:57 jmmv Exp $
#

DISTNAME=	ipw-3.3a
WRKSRC=		${WRKDIR}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER= 	mipam@ibb.net,zuntum@netbsd.org
HOMEPAGE=	http://mjhb.marina-del-rey.ca.us/ipw/
COMMENT= 	"whois" replacement that automatically queries several databases

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ipw ${PREFIX}/bin
	${INSTALL_DATA} ${FILESDIR}/README ${PREFIX}/share/doc/ipw.README

.include "../../mk/bsd.pkg.mk"
