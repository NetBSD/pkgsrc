# $NetBSD: Makefile,v 1.18 2011/08/20 14:10:45 taca Exp $

DISTNAME=	Mail_Mime-1.8.2
CATEGORIES+=	mail

MAINTAINER=	jdolecek@NetBSD.org
COMMENT=	PHP classes to create and manipulation of mime messages

CONFLICTS=	php-pear-Mail_Mime-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

SUBST_CLASSES+=		shbang
SUBST_STAGE.shbang=	post-install
SUBST_FILES.shbang=	${DESTDIR}${PREFIX}/lib/php/doc/Mail_Mime/scripts/phail.php
SUBST_SED.shbang=	-e "s|@prefix@|${PREFIX}|g"

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
