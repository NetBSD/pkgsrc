# $NetBSD: Makefile,v 1.3.2.1 2002/07/01 17:45:00 jlam Exp $
#

DISTNAME=	isic-0.05
CATEGORIES=	net
MASTER_SITES=	http://expert.cc.purdue.edu/~frantzen/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://expert.cc.purdue.edu/~frantzen/
COMMENT=	Ip Stack Integrity Checker (IP, TCP, UDP, ICMP et. al.)

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/isic.README

.include "../../devel/libnet/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
