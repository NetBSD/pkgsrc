# $NetBSD: Makefile,v 1.14 2009/07/08 16:23:59 joerg Exp $
#

DISTNAME=	libjit-0.1.2
CATEGORIES=	devel
MASTER_SITES=	http://download.savannah.gnu.org/releases/dotgnu-pnet/libjit-releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.southern-storm.com.au/libjit.html
COMMENT=	Just-In-Time compilation functionality

PKG_DESTDIR_SUPPORT=	user-destdir

LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake lex yacc makeinfo
GNU_CONFIGURE=		yes
INFO_FILES=		# PLIST

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
