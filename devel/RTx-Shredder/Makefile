# $NetBSD: Makefile,v 1.3 2008/04/30 10:20:20 cube Exp $
#

DISTNAME=	RTx-Shredder-0.03
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=RTx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~ruz/RTx-Shredder/
COMMENT=	Utility to clean a RT database

DEPENDS+=	rt>=3.4.5:../../devel/rt3
BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
BUILD_DEPENDS+=	p5-DBD-SQLite-[0-9]*:../../databases/p5-DBD-SQLite

.include "../../devel/rt3/dirs.mk"

PKG_USERS_VARS+=	APACHE_USER

OWN_DIRS_PERMS+=	${RT_VAR_DIR}/data/RTx-Shredder ${APACHE_USER}	${APACHE_GROUP} 0770
PLIST_SUBST+=		RT_SHARE_DIR=share/rt3

SUBST_CLASSES+=		etcpath
SUBST_FILES.etcpath=	t/utils.pl
SUBST_SED.etcpath=	-e 's,\$$RT::EtcPath,"${RT_SHARE_DIR}/etc",'
SUBST_STAGE.etcpath=	post-patch

PERL5_PACKLIST=		auto/RTx/Shredder/.packlist

REPLACE_PERL+=		sbin/rtx-shredder sbin/rtx-validator

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
