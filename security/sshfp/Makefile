# $NetBSD: Makefile,v 1.8 2014/01/17 23:11:28 wiz Exp $

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
PYTHON_PATCH_SCRIPTS=		sshfp

.include "../../lang/python/application.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
