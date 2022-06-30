# $NetBSD: Makefile,v 1.18 2022/06/30 11:18:35 nia Exp $

PLUGIN=		password

MAINTAINER=	taca@NetBSD.org
COMMENT=	Password change plugin for roundcube
PKGREVISION=	2
LICENSE=	gnu-gpl-v3

DEPENDS+=	tcl-expect>=5.32.1:../../lang/tcl-expect

REPLACE_PERL+=		plugins/password/helpers/change_ldap_pass.pl
REPLACE_PYTHON+=	plugins/password/helpers/chpass-wrapper.py

DISTINFO_FILE=	${PKGDIR}/distinfo

.include "../../mail/roundcube/plugins.mk"
.include "../../lang/perl5/module.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
