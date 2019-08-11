# $NetBSD: Makefile,v 1.32 2019/08/11 13:22:38 wiz Exp $
#

DISTNAME=	foomatic-db-engine-4.0.13
PKGREVISION=	2
CATEGORIES=	print
MASTER_SITES=	http://www.openprinting.org/download/foomatic/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.linuxfoundation.org/collaborate/workgroups/openprinting/database/foomatic
COMMENT=	Foomatic's database engine
LICENSE=	gnu-gpl-v2

# XXX wget should work too
DEPENDS+=	curl-[0-9]*:../../www/curl

GNU_CONFIGURE=	yes
USE_TOOLS+=	file perl gmake

BUILD_DEFS+=	PKG_SYSCONFBASE

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASE}

CONFIGURE_ENV+=	PRINTF=/usr/bin/printf
CONFIGURE_ENV+=	LIBDIR=${PREFIX}/share/foomatic
CONFIGURE_ENV+=	FOOMATIC_RIP=${PREFIX}/bin/foomatic-rip
CONFIGURE_ENV+=	LOCALBASE=${PREFIX}
CONFIGURE_ENV+=	CUPS_PPDS=${PREFIX}/share/cups/model
CONFIGURE_ENV+=	CUPS_ETC=${PKG_SYSCONFBASE}/cups
CONFIGURE_ENV+=	PERL_INSTALLDIRS=vendor

PERL5_CONFIGURE=	no
PERL5_CONFIGURE_DIRS=	lib
PERL5_PACKLIST=		auto/Foomatic/.packlist

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
TOOLS_PLATFORM.file=	# doesn't support -
.endif

SUBST_CLASSES+=		fixpath
SUBST_STAGE.fixpath=	post-build
SUBST_FILES.fixpath=	lib/Foomatic/Defaults.pm
SUBST_SED.fixpath=	-e "s,${TOOLS_DIR}/bin/curl,${BUILDLINK_PREFIX.curl}/bin/curl,g"

# XXX generated but needs to be present before perl5-configure
post-extract:
	${TOUCH} ${WRKSRC}/lib/Foomatic/Defaults.pm

post-configure: perl5-configure

.include "../../lang/perl5/module.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
