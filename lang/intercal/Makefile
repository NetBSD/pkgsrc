# $NetBSD: Makefile,v 1.17 2021/12/27 04:27:10 dholland Exp $
#

DISTNAME=	intercal-0.30
PKGREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.catb.org/~esr/intercal/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.catb.org/~esr/intercal/
COMMENT=	The ultimate language for obfuscation and job security
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=		no
USE_TOOLS+=		flex yacc
GNU_CONFIGURE=		yes
INSTALLATION_DIRS+=	bin lib
INFO_FILES=		yes

# 0.30 still mostly calls itself 0.29
PLIST_SUBST+=	PLISTVERSION=0.29

CONFIGURE_ENV+=		LEX="flex -l"

do-test:
	cd ${WRKSRC}/pit && ${MAKE}

.include "../../mk/bsd.pkg.mk"
