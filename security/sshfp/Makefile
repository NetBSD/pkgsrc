# $NetBSD: Makefile,v 1.11 2016/06/30 18:03:46 wiz Exp $

DISTNAME=	sshfp-1.1.3
PKGREVISION=	4
CATEGORIES=	security net
MASTER_SITES=	http://www.xelerance.com/software/sshfp/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.xelerance.com/software/sshfp/
COMMENT=	Print ssh host key fingerprint resource records
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-dns-[0-9]*:../../net/py-dns

MANCOMPRESSED=			yes
NO_BUILD=			yes
REPLACE_PYTHON=		sshfp

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
