# $NetBSD: Makefile,v 1.44 2004/10/03 00:18:02 tv Exp $

DISTNAME=	knews-1.0b.1
PKGNAME=	knews-1.0
PKGREVISION=	10
CATEGORIES=	news x11
MASTER_SITES=	http://www.matematik.su.se/~kjj/

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://www.matematik.su.se/~kjj/
COMMENT=	X11 newsreader with support for threading and MIME

CONFLICTS=	knews-1.0b0

USE_BUILDLINK3=	YES
USE_IMAKE=	YES

BUILD_DEFS+=	KNEWS_DOMAIN_NAME KNEWS_DOMAIN_FILE USE_INET6

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

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mail/faces/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
