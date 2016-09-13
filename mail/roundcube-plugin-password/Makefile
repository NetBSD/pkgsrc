# $NetBSD: Makefile,v 1.1 2016/09/13 16:00:15 taca Exp $

PLUGIN=		password

MAINTAINER=	taca@NetBSD.org
COMMENT=	Password change plugin for roundcube
LICENSE=	gnu-gpl-v3

PLUGIN=		password

REPLACE_PYTHON=	plugins/password/helpers/chpass-wrapper.py

do-install: plugin-install

.include "../../mail/roundcube/plugins.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
