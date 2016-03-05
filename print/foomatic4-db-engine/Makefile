# $NetBSD: Makefile,v 1.21 2016/03/05 11:29:16 jperkin Exp $
#

DISTNAME=	foomatic-db-engine-4.0.12
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://www.openprinting.org/download/foomatic/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.linuxfoundation.org/collaborate/workgroups/openprinting/database/foomatic
COMMENT=	Foomatic's database engine
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --sysconfdir=${PKG_SYSCONFBASE}
CONFIGURE_ENV+=	PRINTF=/usr/bin/printf
CONFIGURE_ENV+=	LIBDIR=${LOCALBASE}/share/foomatic
CONFIGURE_ENV+=	FOOMATIC_RIP=${LOCALBASE}/bin/foomatic-rip
CONFIGURE_ENV+=	LOCALBASE=${LOCALBASE}
CONFIGURE_ENV+=	CUPS_ETC=${PKG_SYSCONFBASE}/cups
CONFIGURE_ENV+=	PERL_INSTALLDIRS=vendor
USE_TOOLS+=	file perl gmake
PERL5_PACKLIST=	auto/Foomatic/.packlist

PERL5_CONFIGURE=	no
PERL5_CONFIGURE_DIRS=	lib

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
TOOLS_PLATFORM.file=	# doesn't support -
.endif

# XXX generated but needs to be present before perl5-configure
post-extract:
	${TOUCH} ${WRKSRC}/lib/Foomatic/Defaults.pm

post-configure: perl5-configure

SUBST_CLASSES+=		fixpath
SUBST_STAGE.fixpath=	post-build
SUBST_FILES.fixpath=	lib/Foomatic/Defaults.pm
SUBST_SED.fixpath=	-e "s,${TOOLS_DIR}/bin/curl,${BUILDLINK_PREFIX.curl}/bin/curl,g"

.include "../../lang/perl5/module.mk"
.include "../../textproc/libxml2/buildlink3.mk"
# XXX wget should work too
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
