# $NetBSD: Makefile,v 1.3 2003/09/26 11:20:27 jmmv Exp $

DISTNAME=	maradns-1.0.18
CATEGORIES=	net
MASTER_SITES=	http://www.maradns.org/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pancake@phreaker.net
HOMEPAGE=	http://www.maradns.org/
COMMENT=	Secure DNS server for *NIX systems

USE_PKGINSTALL=	YES
RCD_SCRIPTS=	maradns

EGDIR=		${PREFIX}/share/examples/maradns
CONF_FILES=	${EGDIR}/example_mararc ${PKG_SYSCONFDIR}/mararc

post-install:
	${MV} ${PREFIX}/doc/${DISTNAME} ${PREFIX}/share/doc/maradns
	${RMDIR} ${PREFIX}/doc
	${MV} ${PREFIX}/share/doc/maradns/examples \
		${PREFIX}/share/examples/maradns

.include "../../mk/bsd.pkg.mk"
