# $NetBSD: Makefile,v 1.7 2005/12/29 06:22:00 jlam Exp $
#

DISTNAME=       latd-1.18
CATEGORIES=	net
MASTER_SITES=   ${MASTER_SITE_SOURCEFORGE:=linux-decnet/}

MAINTAINER=	fredette@theory.lcs.mit.edu
HOMEPAGE=	http://theory.lcs.mit.edu/~fredette/latd/index.html
COMMENT=	The linux-decnet project's LAT protocol suite

NOT_FOR_PLATFORM=	Interix-*-* # no direct ethernet support

GNU_CONFIGURE=	yes

CPPFLAGS+=	-DPREFIX="\"${PREFIX}\""

EGDIR=		${PREFIX}/share/examples/latd
CONF_FILES=	${EGDIR}/latd.conf ${PKG_SYSCONFDIR}/latd.conf

.include "../../mk/bsd.pkg.mk"
