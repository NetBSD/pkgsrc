# $NetBSD: Makefile,v 1.1 2002/02/07 19:09:37 jonb Exp $
#

DISTNAME=	arch-1.0pre6
CATEGORIES=	devel
MASTER_SITES=	ftp://regexps.com/pub/src/arch/

MAINTAINER=	schmonz+netbsd@schmonz.com
HOMEPAGE=	http://www.regexps.com/
COMMENT=	revision control system ideal for widely distributed development

WRKSRC=		${WRKDIR}/${DISTNAME}/src/=build

USE_GMAKE=	# defined

HAS_CONFIGURE=		# defined
CONFIGURE_SCRIPT=	../configure
CONFIGURE_ARGS+=	--prefix ${PREFIX}

post-extract:
	${MKDIR} ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
