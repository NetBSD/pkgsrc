# $NetBSD: Makefile,v 1.1.1.1 2001/03/28 07:41:59 zuntum Exp $
#

DISTNAME=	ipw-3.3a
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER= 	mipam@ibb.net,zuntum@netbsd.org
HOMEPAGE=	http://mjhb.marina-del-rey.ca.us/ipw/
COMMENT= 	"whois" replacement that automatically queries several databases

WRKSRC=		${WRKDIR}

post-install:
	${INSTALL_DATA} ${FILESDIR}/README ${PREFIX}/share/doc/ipw.README

.include "../../mk/bsd.pkg.mk"
