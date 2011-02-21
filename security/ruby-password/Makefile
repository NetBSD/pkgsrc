# $NetBSD: Makefile,v 1.5 2011/02/21 16:01:19 taca Exp $

DISTNAME=	ruby-password-0.5.3
PKGNAME=	${DISTNAME:S/ruby/${RUBY_PKGPREFIX}/}
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	http://www.caliban.org/files/ruby/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.caliban.org/ruby/ruby-password.shtml
COMMENT=	Suite of password handling methods for Ruby
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${RUBY_PKGPREFIX}-termios>=0.9.5:../../comms/ruby-termios

USE_RUBY_EXTCONF=	yes

SUBST_CLASSES+=		pwdict
SUBST_MESSAGE.pwdict=	Fixing a hardcoded path to pw_dict.pwd.
SUBST_STAGE.pwdict=	pre-configure
SUBST_FILES.pwdict=	extconf.rb
SUBST_SED.pwdict=	-e 's,/usr/local/lib/,${BUILDLINK_PREFIX.libcrack}/libdata/,g'

.include "../../lang/ruby/modules.mk"
.include "../../security/libcrack/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
