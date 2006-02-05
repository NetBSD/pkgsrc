# $NetBSD: Makefile,v 1.5 2006/02/05 23:10:29 joerg Exp $

DISTNAME=	SOAP-0.8.1
PKGREVISION=	1
CATEGORIES+=	net

MAINTAINER=	jdolecek@NetBSD.org
COMMENT=	SOAP Client/Server for PHP

DEPENDS+=	pear-Mail_Mime>=1.2:../../mail/pear-Mail_Mime
DEPENDS+=	pear-HTTP_Request>=1.2:../../www/pear-HTTP_Request
DEPENDS+=	pear-Net_URL>=1.0:../../net/pear-Net_URL
DEPENDS+=	pear-Net_DIME>=0.3:../../net/pear-Net_DIME

PEAR_DIRRM_BASEDIR=     yes

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
