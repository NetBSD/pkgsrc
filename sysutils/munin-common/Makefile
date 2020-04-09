# $NetBSD: Makefile,v 1.3 2020/04/09 15:00:47 tm Exp $
#

PKGNAME=	${DISTNAME:S/munin/munin-common/}
COMMENT=	Common components between a munin node and master

.include "../../sysutils/munin-common/Makefile.common"

# Adjust WRKSRC for the Perl module framework, but keep the same
# patch base directory
WRKSRC=			${WRKDIR}/${DISTNAME}/common
PATCH_ARGS=		-d ${WRKSRC}/.. --forward -E ${PATCH_STRIP}

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Munin/Common/.packlist

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	lib/Munin/Common/Defaults.pm
SUBST_VARS.paths=	PKG_SYSCONFDIR MUNIN_DBDIR MUNIN_LIBDIR \
			MUNIN_LOGDIR MUNIN_STATEDIR MUNIN_WWWDIR \
			MUNIN_PLUGSTATE PERL5

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
