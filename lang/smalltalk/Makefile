# $NetBSD: Makefile,v 1.4 2001/05/10 23:41:29 dmcmahill Exp $
#

DISTNAME=	smalltalk-1.8.5
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU:=smalltalk/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/smalltalk/smalltalk.html
COMMENT=	the GNU implementation of the Smalltalk-80 language

# smalltalk does not support 64-bit platforms yet (as of 1.8.5)
NOT_FOR_PLATFORM=	*-*-alpha  *-*-sparc64

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

INFO_FILES=	gst.info

.include "../../mk/bsd.pkg.mk"
