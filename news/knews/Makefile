# $NetBSD: Makefile,v 1.15 1998/08/20 15:17:22 tsarna Exp $
#

DISTNAME=	knews-1.0b.0
PKGNAME=	knews-1.0b0
CATEGORIES=	news
MASTER_SITES=	http://www.matematik.su.se/~kjj/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.matematik.su.se/~kjj/

DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	png-1.0.2:../../graphics/png
DEPENDS+=	xpm-3.4k:../../graphics/xpm

USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/knews

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
