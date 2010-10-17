# $NetBSD: Makefile,v 1.15 2010/10/17 01:06:14 tron Exp $

DISTNAME=	Mail_Mime-1.8.0
PKGREVISION=	1
CATEGORIES+=	mail

MAINTAINER=	jdolecek@NetBSD.org
COMMENT=	PHP classes to create and manipulation of mime messages

CONFLICTS=	php-pear-Mail_Mime-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

SUBST_CLASSES+=		shbang
SUBST_STAGE.shbang=	post-install
SUBST_FILES.shbang=	${PREFIX}/lib/php/doc/Mail_Mime/scripts/phail.php
SUBST_SED.shbang=	-e "s|@prefix@|${PREFIX}|g"


.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
