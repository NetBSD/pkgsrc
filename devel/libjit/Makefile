# $NetBSD: Makefile,v 1.12 2007/11/17 12:04:11 rillig Exp $
#

DISTNAME=	libjit-0.0.4
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.southern-storm.com.au/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.southern-storm.com.au/libjit.html
COMMENT=	Just-In-Time compilation functionality

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake lex yacc makeinfo
GNU_CONFIGURE=		yes
INFO_FILES=		# PLIST

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
