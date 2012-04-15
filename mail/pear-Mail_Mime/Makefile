# $NetBSD: Makefile,v 1.20 2012/04/15 22:01:02 wiz Exp $

DISTNAME=	Mail_Mime-1.8.3
CATEGORIES+=	mail

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	PHP classes to create and manipulation of mime messages

CONFLICTS=	php-pear-Mail_Mime-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

SUBST_CLASSES+=		shbang
SUBST_STAGE.shbang=	post-install
SUBST_FILES.shbang=	${DESTDIR}${PREFIX}/lib/php/doc/Mail_Mime/scripts/phail.php
SUBST_SED.shbang=	-e "s|@prefix@|${PREFIX}|g"

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
