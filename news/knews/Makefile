# $NetBSD: Makefile,v 1.37 2001/12/02 14:40:20 tron Exp $

DISTNAME=	knews-1.0b.1
PKGNAME=	knews-1.0
PKGREVISION=	7
CATEGORIES=	news x11
MASTER_SITES=	http://www.matematik.su.se/~kjj/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.matematik.su.se/~kjj/
COMMENT=	X11 newsreader with support for threading and MIME

DEPENDS+=	faces>=1.6.1:../../mail/faces
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	png>=1.0.11:../../graphics/png

CONFLICTS=	knews-1.0b0

USE_IMAKE=	YES
USE_XPM=	YES

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
	${ECHO} >>${WRKSRC}/configure.h \
	"#define DOMAIN_FILE \"${KNEWS_DOMAIN_FILE}\""
.elif defined(KNEWS_DOMAIN_NAME)
	${ECHO} >>${WRKSRC}/configure.h \
	"#define DOMAIN_NAME \"${KNEWS_DOMAIN_NAME}\""
.endif
.if defined(USE_INET6) && ${USE_INET6} == YES
	${ECHO} >>${WRKSRC}/configure.h "#define USE_INET6 YES"
.endif

.include "../../mk/bsd.pkg.mk"
