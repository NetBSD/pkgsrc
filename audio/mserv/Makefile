# $NetBSD: Makefile,v 1.2 2002/02/15 00:42:31 hubertf Exp $
#

DISTNAME=	mserv-0.33
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.mserv.org/download/

MAINTAINER=	martin@netbsd.org
HOMEPAGE=	http://www.mserv.org/
COMMENT=	local centralised music server environment

ALL_TARGET=	default
REPLACE_PERL=	mserv/mservedit webclient/main.cgi webclient/margin.cgi webclient/mserv.cgi

post-install:
		${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mserv
		${INSTALL_DATA} \
			${WRKSRC}/INSTALL \
			${WRKSRC}/LICENSE \
			${PREFIX}/share/doc/mserv
		${INSTALL_DATA_DIR} ${PREFIX}/share/mserv/webclient
		${INSTALL_DATA} \
			${WRKSRC}/webclient/* \
			${PREFIX}/share/mserv/webclient

.include "../../mk/bsd.pkg.mk"
