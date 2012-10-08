# $NetBSD: Makefile,v 1.23 2012/10/08 12:19:25 asau Exp $

DISTNAME=	Mail_Mime-1.8.5
CATEGORIES+=	mail

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	PHP classes to create and manipulation of mime messages

CONFLICTS=	php-pear-Mail_Mime-[0-9]*

SUBST_CLASSES+=		shbang
SUBST_STAGE.shbang=	post-install
SUBST_FILES.shbang=	${DESTDIR}${PREFIX}/lib/php/doc/Mail_Mime/scripts/phail.php
SUBST_SED.shbang=	-e "s|@prefix@|${PREFIX}|g"

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
