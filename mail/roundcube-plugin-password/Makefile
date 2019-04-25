# $NetBSD: Makefile,v 1.4 2019/04/25 07:33:04 maya Exp $

PLUGIN=		password

MAINTAINER=	taca@NetBSD.org
COMMENT=	Password change plugin for roundcube
PKGREVISION=	1
LICENSE=	gnu-gpl-v3

PLUGIN=		password

REPLACE_PERL+=		plugins/password/helpers/change_ldap_pass.pl
REPLACE_PYTHON+=	plugins/password/helpers/chpass-wrapper.py

do-install: plugin-install

.include "../../mail/roundcube/plugins.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
