# $NetBSD: Makefile,v 1.14 2014/07/27 08:38:33 tron Exp $

DISTNAME=	ipw-3.3a
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	mipam@ibb.net
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
