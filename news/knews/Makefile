# $NetBSD: Makefile,v 1.8 1998/04/22 23:42:19 tron Exp $
#

DISTNAME=	knews-1.0b.0
PKGNAME=	knews-1.0b0
CATEGORIES=	news
MASTER_SITES=	http://www.matematik.su.se/~kjj/

MAINTAINER=	tron@netbsd.org

DEPENDS+=	jpeg-6a:../../graphics/jpeg
DEPENDS+=	png-0.96:../../graphics/png
DEPENDS+=	xpm-3.4j:../../graphics/xpm

USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/knews

CAT1=		knews.0

# Set DOMAIN_NAME to a string appended to the From: header or
# assign it a file from which the domain name is read.
post-extract:
.if !defined(DOMAIN_FILE) && !defined(DOMAIN_NAME)
	@${ECHO_MSG} "Type \"make DOMAIN_NAME=xyz\" to set the domain name."
.elif defined(DOMAIN_FILE)
	@${ECHO_MSG} "Reading \"From:\" domain from file \"${DOMAIN_FILE}\"."
.else
	@${ECHO_MSG} "Using \"${DOMAIN_NAME}\" as the \"From:\" domain name."
.endif

post-patch:
.if defined(DOMAIN_FILE)
	${ECHO_MSG} >>${WRKSRC}/configure.h \
	"#define DOMAIN_FILE \"${DOMAIN_FILE}\""
.elif defined(DOMAIN_NAME)
	${ECHO_MSG} >>${WRKSRC}/configure.h \
	"#define DOMAIN_NAME \"${DOMAIN_NAME}\""
.endif

.include "../../mk/bsd.pkg.mk"
