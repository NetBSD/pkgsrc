# $NetBSD: Makefile,v 1.25 2000/03/21 22:40:56 tron Exp $

DISTNAME=	knews-1.0b.1
PKGNAME=	knews-1.0b1
CATEGORIES=	news x11
MASTER_SITES=	http://www.matematik.su.se/~kjj/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.matematik.su.se/~kjj/

DEPENDS+=	faces-1.6.1:../../mail/faces
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	png>=1.0.6:../../graphics/png
DEPENDS+=	xpm-3.4k:../../graphics/xpm

CONFLICTS=	knews-1.0b0

USE_IMAKE=	yes

BUILD_DEFS+=	KNEWS_DOMAIN_NAME KNEWS_DOMAIN_FILE

.include "../../mk/bsd.prefs.mk"

# Set KNEWS_DOMAIN_NAME to a string appended to the "From:" header or
# KNEWS_DOMAIN_FILE to a file from which the domain name will be read.
post-extract:
.if !defined(KNEWS_DOMAIN_FILE) && !defined(KNEWS_DOMAIN_NAME)
	@${ECHO_MSG} "Type \"make KNEWS_DOMAIN_NAME=xyz\" to set the domain name."
.elif defined(KNEWS_DOMAIN_FILE)
	@${ECHO_MSG} "Reading \"From:\" domain from file \"${KNEWS_DOMAIN_FILE}\"."
.else
	@${ECHO_MSG} "Using \"${KNEWS_DOMAIN_NAME}\" as the \"From:\" domain name."
.endif

post-patch:
.if defined(KNEWS_DOMAIN_FILE)
	${ECHO_MSG} >>${WRKSRC}/configure.h \
	"#define DOMAIN_FILE \"${KNEWS_DOMAIN_FILE}\""
.elif defined(KNEWS_DOMAIN_NAME)
	${ECHO_MSG} >>${WRKSRC}/configure.h \
	"#define DOMAIN_NAME \"${KNEWS_DOMAIN_NAME}\""
.endif

.include "../../mk/bsd.pkg.mk"
