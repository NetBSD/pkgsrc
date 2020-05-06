# $NetBSD: Makefile,v 1.7.2.1 2020/05/06 10:01:06 bsiegert Exp $

PLUGIN=		password
PKGREVISION=	1

MAINTAINER=	taca@NetBSD.org
COMMENT=	Password change plugin for roundcube
LICENSE=	gnu-gpl-v3

REPLACE_PERL+=		plugins/password/helpers/change_ldap_pass.pl
REPLACE_PYTHON+=	plugins/password/helpers/chpass-wrapper.py

DISTINFO_FILE=	${PKGDIR}/distinfo

.include "../../mail/roundcube/plugins.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
