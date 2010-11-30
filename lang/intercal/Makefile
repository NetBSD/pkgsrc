# $NetBSD: Makefile,v 1.11 2010/11/30 20:13:29 drochner Exp $
#

DISTNAME=	intercal-0.29
CATEGORIES=	lang
MASTER_SITES=	http://www.catb.org/~esr/intercal/

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://www.catb.org/~esr/intercal/
COMMENT=	The ultimate language for obfuscation and job security

MAKE_JOBS_SAFE=		no
USE_TOOLS+=	flex yacc
GNU_CONFIGURE=	yes
PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS+=	bin lib
INFO_FILES=	yes

CONFIGURE_ENV+=		LEX="flex -l"

do-test:
	cd ${WRKSRC}/pit && ${MAKE}

.include "../../mk/bsd.pkg.mk"
