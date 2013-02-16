# $NetBSD: Makefile,v 1.63 2013/02/16 11:24:03 wiz Exp $

DISTNAME=	knews-1.0b.1
PKGNAME=	knews-1.0
PKGREVISION=	17
CATEGORIES=	news x11
MASTER_SITES=	# http://www.matematik.su.se/~kjj/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.matematik.su.se/~kjj/
COMMENT=	X11 newsreader with support for threading and MIME

CONFLICTS=	knews-1.0b0

USE_IMAKE=	YES

BUILD_DEFS+=	KNEWS_DOMAIN_NAME KNEWS_DOMAIN_FILE

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.knews
PKG_SUPPORTED_OPTIONS=	inet6
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

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
.if !empty(PKG_OPTIONS:Minet6)
	${ECHO} >>${WRKSRC}/configure.h "#define USE_INET6 YES"
.endif

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mail/faces/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
