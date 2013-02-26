# $NetBSD: Makefile,v 1.1 2013/02/26 00:13:00 hubertf Exp $
#

DISTNAME=	ansible-1.0
CATEGORIES=	sysutils
MASTER_SITES=	http://ansible.cc/releases/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ansible.cc/
COMMENT=	SSH-based configuration management, deployment, and task execution system
LICENSE=	gnu-gpl-v3

#USE_LANGUAGES=	# none
USE_TOOLS+=	gmake

REPLACE_PYTHON+=library/*

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	lib/ansible/constants.py
SUBST_SED.prefix=	-e "s,@PREFIX@,${PREFIX},"

SUBST_CLASSES+=		localbase
SUBST_STAGE.localbase=	pre-configure
SUBST_FILES.localbase=	\
			lib/ansible/callbacks.py \
			library/mysql_db \
			library/ping \
			library/pkgin \
			library/raw \
			library/setup \
			library/slurp \
			library/virt
SUBST_SED.localbase=	-e "s,@LOCALBASE@,${LOCALBASE},"

DEPENDS+=		${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
DEPENDS+=		${PYPKGPREFIX}-paramiko-[0-9]*:../../security/py-paramiko
DEPENDS+=		${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
