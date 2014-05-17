# $NetBSD: Makefile,v 1.10 2014/05/17 16:10:48 wiz Exp $

DISTNAME=	sshfp-1.1.3
PKGREVISION=	4
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
