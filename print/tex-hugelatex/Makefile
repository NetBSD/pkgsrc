# $NetBSD: Makefile,v 1.21 2009/01/08 22:13:23 minskim Exp $
#

DISTNAME=	hugelatex-2.0
PKGNAME=	tex-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	print
MASTER_SITES=	# none
DISTFILES=	# nada

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	LaTeX format files with large limits

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	# nothing
NO_CHECKSUM=	yes
NO_BUILD=	yes

PKG_SYSCONFSUBDIR=	texmf

FILES_SUBST+=	PKG_TEXMFPREFIX=${PKG_TEXMFPREFIX:Q}

CHECK_FILES_SKIP+=	${PKG_TEXMFPREFIX}/web2c/hugelatex.fmt
CHECK_FILES_SKIP+=	${PKG_TEXMFPREFIX}/web2c/hugelatex.log


.include "../../print/teTeX/module.mk"

do-install:
	${LN} -s latex ${PREFIX}/bin/hugelatex

.include "../../mk/bsd.pkg.mk"
