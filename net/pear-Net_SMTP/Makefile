# $NetBSD: Makefile,v 1.9 2010/02/04 16:36:05 joerg Exp $

DISTNAME=	Net_SMTP-1.3.0
CATEGORIES+=	net mail

MAINTAINER=	jdolecek@NetBSD.org
COMMENT=	PHP classes to provide SMTP Interface

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-pear-Net_SMTP-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Net_Socket>=1.0.7:../../net/pear-Net_Socket

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
