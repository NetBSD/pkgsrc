# $NetBSD: Makefile,v 1.11 2010/03/15 16:39:39 taca Exp $

DISTNAME=	Net_SMTP-1.4.2
CATEGORIES+=	net mail

MAINTAINER=	jdolecek@NetBSD.org
COMMENT=	PHP classes to provide SMTP Interface

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-pear-Net_SMTP-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_Socket>=1.0.7:../../net/pear-Net_Socket

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
