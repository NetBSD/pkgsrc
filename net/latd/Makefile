# $NetBSD: Makefile,v 1.15 2023/08/02 19:21:56 nia Exp $
#

DISTNAME=	latd-1.21
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=linux-decnet/}

MAINTAINER=	fredette@theory.lcs.mit.edu
#HOMEPAGE=	http://theory.lcs.mit.edu/~fredette/latd/index.html
COMMENT=	The linux-decnet project's LAT protocol suite

NOT_FOR_PLATFORM=	Interix-*-* # no direct ethernet support

GNU_CONFIGURE=	yes

USE_LANGUAGES=	c c++

CPPFLAGS+=	-DPREFIX="\"${PREFIX}\""

EGDIR=		${PREFIX}/share/examples/latd
CONF_FILES=	${EGDIR}/latd.conf.sample ${PKG_SYSCONFDIR}/latd.conf

# Fails with C++14 default language.
FORCE_CXX_STD=	c++03

.include "../../mk/bsd.pkg.mk"
