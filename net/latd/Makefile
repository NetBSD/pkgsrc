# $NetBSD: Makefile,v 1.16 2025/04/21 21:04:58 wiz Exp $

DISTNAME=	latd-1.21
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=linux-decnet/}

MAINTAINER=	fredette@theory.lcs.mit.edu
#HOMEPAGE=	http://theory.lcs.mit.edu/~fredette/latd/index.html
COMMENT=	The linux-decnet project's LAT protocol suite

GNU_CONFIGURE=	yes

USE_LANGUAGES=	c c++

CPPFLAGS+=	-DPREFIX="\"${PREFIX}\""

EGDIR=		${PREFIX}/share/examples/latd
CONF_FILES=	${EGDIR}/latd.conf.sample ${PKG_SYSCONFDIR}/latd.conf

# Fails with C++14 default language.
FORCE_CXX_STD=	c++03

.include "../../mk/bsd.pkg.mk"
