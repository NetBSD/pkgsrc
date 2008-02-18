# $NetBSD: Makefile,v 1.13 2008/02/18 15:51:44 xtraeme Exp $
#

DISTNAME=	libjit-0.1.0
#PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://download.savannah.gnu.org/releases/dotgnu-pnet/

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
