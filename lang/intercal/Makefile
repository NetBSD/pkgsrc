# $NetBSD: Makefile,v 1.13 2012/12/12 10:44:10 wiz Exp $
#

DISTNAME=	intercal-0.29
CATEGORIES=	lang
MASTER_SITES=	http://www.catb.org/~esr/intercal/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.catb.org/~esr/intercal/
COMMENT=	The ultimate language for obfuscation and job security

MAKE_JOBS_SAFE=		no
USE_TOOLS+=	flex yacc
GNU_CONFIGURE=	yes
INSTALLATION_DIRS+=	bin lib
INFO_FILES=	yes

CONFIGURE_ENV+=		LEX="flex -l"

do-test:
	cd ${WRKSRC}/pit && ${MAKE}

.include "../../mk/bsd.pkg.mk"
