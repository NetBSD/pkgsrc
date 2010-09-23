# $NetBSD: Makefile,v 1.14 2010/09/23 08:03:02 taca Exp $

DISTNAME=	Mail_Mime-1.8.0
CATEGORIES+=	mail

MAINTAINER=	jdolecek@NetBSD.org
COMMENT=	PHP classes to create and manipulation of mime messages

CONFLICTS=	php-pear-Mail_Mime-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

SUBST_CLASSES+=		shbang
SUBST_STAGE.shbang=	pre-install
SUBST_FILES.shbang=	scripts/phail.php
SUBST_SED.shbang=	-e "s|@prefix@|${PREFIX}|g"


.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
