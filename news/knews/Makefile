# New ports collection Makefile for: knews
# Version required:	0.9.8
# Date created:         30th November 1997
# Whom:                 tron
#
# $NetBSD: Makefile,v 1.4 1998/01/29 16:51:27 tron Exp $
#

DISTNAME=	knews-0.9.8
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.nada.kth.se/home/su95-kjo/knews/ \
		ftp://ftp.cs.tu-berlin.de/pub/net/news/knews/

MAINTAINER=	tron@netbsd.org

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/knews

# Set DOMAIN_NAME to a string appended to the From: header or
# assign it a file from which the domain name is read.
post-extract:
.if !defined(DOMAIN_NAME)
	@${ECHO_MSG} "Type \"make DOMAIN_NAME=xyz\" to set the domain name."
.else
	@${ECHO_MSG} "Using \"${DOMAIN_NAME}\" as the From: domain name."
.endif

post-patch:
.if defined(DOMAIN_NAME)
	${ECHO_MSG} >>${WRKSRC}/configure.h \
	"#define DOMAIN_NAME \"${DOMAIN_NAME}\""
.endif

.include <bsd.port.mk>
