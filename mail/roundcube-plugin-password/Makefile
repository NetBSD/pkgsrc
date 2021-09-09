# $NetBSD: Makefile,v 1.15 2021/09/09 01:11:43 khorben Exp $

PLUGIN=		password
PKGREVISION=	2

MAINTAINER=	taca@NetBSD.org
COMMENT=	Password change plugin for roundcube
LICENSE=	gnu-gpl-v3

DEPENDS+=	tcl-expect>=5.32.1:../../lang/tcl-expect

REPLACE_PERL+=		plugins/password/helpers/change_ldap_pass.pl
REPLACE_PYTHON+=	plugins/password/helpers/chpass-wrapper.py

DISTINFO_FILE=	${PKGDIR}/distinfo

.include "../../mail/roundcube/plugins.mk"
.include "../../lang/perl5/module.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
