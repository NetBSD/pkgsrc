# $NetBSD: Makefile,v 1.2 2001/02/17 18:18:59 wiz Exp $
#

DISTNAME=	isic-0.05
CATEGORIES=	net
MASTER_SITES=	http://expert.cc.purdue.edu/~frantzen/
EXTRACT_SUFX=	.tgz

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://expert.cc.purdue.edu/~frantzen/
COMMENT=	Ip Stack Integrity Checker (IP, TCP, UDP, ICMP et. al.)

DEPENDS+=	libnet-1.*:../../devel/libnet

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	CFLAGS="-I${LOCALBASE}/include"

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/isic.README

.include "../../mk/bsd.pkg.mk"
