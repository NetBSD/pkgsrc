# $NetBSD: Makefile,v 1.9 2014/01/25 10:45:21 wiz Exp $

DISTNAME=	sshfp-1.1.3
PKGREVISION=	3
CATEGORIES=	security net
MASTER_SITES=	http://www.xelerance.com/software/sshfp/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.xelerance.com/software/sshfp/
COMMENT=	Print ssh host key fingerprint resource records
LICENSE=	gnu-gpl-v2

PYTHON_VERSIONED_DEPENDENCIES=	dns

MANCOMPRESSED=			yes
NO_BUILD=			yes
REPLACE_PYTHON=		sshfp

.include "../../lang/python/application.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
