# $NetBSD: Makefile,v 1.13 2012/10/23 17:18:29 asau Exp $
#

DISTNAME=	ipw-3.3a
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	mipam@ibb.net
HOMEPAGE=	http://mjhb.marina-del-rey.ca.us/ipw/
COMMENT=	"whois" replacement that automatically queries several databases

WRKSRC=		${WRKDIR}

INSTALLATION_DIRS=	bin share/doc

LIBS.SunOS+=	-lnsl -lsocket
MAKE_ENV+=	LIBS=${LIBS:M*:Q}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ipw ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${FILESDIR}/README \
			${DESTDIR}${PREFIX}/share/doc/ipw.README

.include "../../mk/bsd.pkg.mk"
