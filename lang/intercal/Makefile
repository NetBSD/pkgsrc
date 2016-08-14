# $NetBSD: Makefile,v 1.14 2016/08/14 13:39:29 mef Exp $
#

DISTNAME=	intercal-0.30
CATEGORIES=	lang
MASTER_SITES=	http://www.catb.org/~esr/intercal/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.catb.org/~esr/intercal/
COMMENT=	The ultimate language for obfuscation and job security
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=		no
USE_TOOLS+=	flex yacc
GNU_CONFIGURE=	yes
INSTALLATION_DIRS+=	bin lib
INFO_FILES=	yes

CONFIGURE_ENV+=		LEX="flex -l"

do-test:
	cd ${WRKSRC}/pit && ${MAKE}

.include "../../mk/bsd.pkg.mk"
