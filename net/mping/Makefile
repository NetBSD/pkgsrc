# $NetBSD: Makefile,v 1.1.1.1 2006/09/07 10:06:26 rillig Exp $

DISTNAME=	mping-2.01
CATEGORIES=	net
MASTER_SITES=	http://mping.uninett.no/

MAINTAINER=	miwi@FreeBSD.org
HOMEPAGE=	http://mping.uninett.no/
COMMENT=	Mping network statistics collector

GNU_CONFIGURE=		yes
INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/mping ${PREFIX}/sbin/mping
	${INSTALL_MAN} ${WRKSRC}/man/mping.8 ${PREFIX}/${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
