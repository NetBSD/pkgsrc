# $NetBSD: Makefile,v 1.17 2017/01/01 14:43:56 wiz Exp $

DISTNAME=	lshell-0.9.16
CATEGORIES=	shells python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lshell/}

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://ghantoos.org/limited-shell-lshell/
COMMENT=	Lshell restricts user's environment to specified commands
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-readline>=0nb2:../../devel/py-readline

PKG_GROUPS=	lshellg
PKG_SHELL=	bin/lshell

USE_LANGUAGES=		# none

PYDISTUTILSPKG=		yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not yet ported as of 0.9.16

EGDIR=			share/examples/lshell

SUBST_CLASSES+=		setup
SUBST_STAGE.setup=	post-patch
SUBST_FILES.setup=	setup.py
SUBST_SED.setup=	-e 's,/etc,${EGDIR},'
SUBST_SED.setup+=	-e 's,share/man,${PKGMANDIR},'

INSTALLATION_DIRS+=	${EGDIR} ${EGDIR}/logrotate.d ${PKGMANDIR}/man1

CONF_FILES=		${PREFIX}/${EGDIR}/lshell.conf \
			${PKG_SYSCONFDIR}/lshell.conf

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
