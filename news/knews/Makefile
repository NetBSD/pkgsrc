# $NetBSD: Makefile,v 1.1.1.1 1997/12/17 23:40:56 hubertf Exp $
# New ports collection Makefile for: knews
# Version required:	0.9.8
# Date created:         30th November 1997
# Whom:                 tron
#

DISTNAME=	knews-0.9.8
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.nada.kth.se/home/su95-kjo/knews/ \
		ftp://ftp.cs.tu-berlin.de/pub/net/news/knews/

MAINTAINER=	tron@lyssa.owl.de

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes
USE_X11=	yes
WRKSRC=		$(WRKDIR)/knews

pre-fetch:
.if !defined(DOMAIN_NAME)
	@${ECHO_MSG} "Type \"make DOMAIN_NAME=xyz\" to set the domain name."
.else
	@${ECHO_MSG} "Using \"${DOMAIN_NAME}\" as the domain name."
.endif

post-patch:
.if defined(DOMAIN_NAME)
	${ECHO_MSG} >>${WRKSRC}/configure.h \
	"#define DOMAIN_NAME \"${DOMAIN_NAME}\""
.endif

.include <bsd.port.mk>
