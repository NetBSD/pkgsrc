# $NetBSD: Makefile,v 1.6 2019/09/01 13:10:39 taca Exp $

PLUGIN=		password

MAINTAINER=	taca@NetBSD.org
COMMENT=	Password change plugin for roundcube
LICENSE=	gnu-gpl-v3

REPLACE_PERL+=		plugins/password/helpers/change_ldap_pass.pl
REPLACE_PYTHON+=	plugins/password/helpers/chpass-wrapper.py

do-install: plugin-install

.include "../../mail/roundcube/plugins.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
