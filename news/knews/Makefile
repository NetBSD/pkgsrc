# $NetBSD: Makefile,v 1.20 1999/08/18 08:31:13 agc Exp $

DISTNAME=	knews-1.0b.1
PKGNAME=	knews-1.0b1
CATEGORIES=	news x11
MASTER_SITES=	http://www.matematik.su.se/~kjj/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.matematik.su.se/~kjj/

DEPENDS+=	faces-1.6.1:../../mail/faces
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	png-1.0.3:../../graphics/png
DEPENDS+=	xpm-3.4k:../../graphics/xpm

CONFLICTS=	knews-1.0b0

USE_IMAKE=	yes

BUILD_DEFS+=	DOMAIN_NAME

.include "../../mk/bsd.prefs.mk"

# Set DOMAIN_NAME to a string appended to the "From:" header or
# DOMAIN_FILE to a file from which the domain name will be read.
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
