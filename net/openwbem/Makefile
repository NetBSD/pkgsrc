# $NetBSD: Makefile,v 1.12 2018/08/22 09:45:56 wiz Exp $

DISTNAME=	openwbem-3.2.2
PKGREVISION=	6
CATEGORIES=	net devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openwbem/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.openwbem.org/
COMMENT=	Web-based Enterprise Management software

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	ac_cv_path_TRUE_PATHNAME=true ac_cv_path_FALSE_PATHNAME=false
USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
USE_LANGUAGES+=	c c++

INSTALLATION_DIRS+=	etc/openwbem include/openwbem var/openwbem
INSTALLATION_DIRS+=	share/openwbem lib/openwbem share/examples/openwbem
INSTALLATION_DIRS+=	lib/openwbem/services lib/openwbem/requesthandlers
INSTALLATION_DIRS+=	lib/openwbem/provifcs lib/openwbem/c++providers
INSTALLATION_DIRS+=	lib/authentication

PKG_SYSCONFSUBDIR=	openwbem
EGDIR=			${PREFIX}/share/examples/openwbem
CONF_FILES+=		${EGDIR}/openwbem.conf \
                        ${PKG_SYSCONFDIR}/openwbem.conf
CONF_FILES+=		${EGDIR}/owgencert \
                        ${PKG_SYSCONFDIR}/owgencert
CONF_FILES+=		${EGDIR}/ssleay.cnf \
                        ${PKG_SYSCONFDIR}/ssleay.cnf


SUBST_CLASSES+=		mkdir
SUBST_STAGE.mkdir=	pre-configure
SUBST_FILES.mkdir=	${WRKSRC}/db/db/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/mof/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/wql/common/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/wql/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/xml/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/http/client/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/http/common/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/provideragent/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/providerifcs/cpp/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/providerifcs/npi/common/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/providerifcs/npi/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/providerifcs/cmpi/common/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/providerifcs/cmpi/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/providerifcs/perl/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/providerifcs/remote/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/repositories/hdb/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/repositories/tdbcr/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/cimom/embedded/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/cimom/common/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/cimom/server/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/cimom/indication/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/client/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/common/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/authorizers/simple2/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/authorizers/simple/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/authenticators/aix/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/authenticators/pam/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/authenticators/pamcl/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/authenticators/nonauthenticating/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/authenticators/simple/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/services/http/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/provider/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/requesthandlers/binary/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/requesthandlers/cimxml/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/cimxmllistener/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/providers/cpp/polled/slp/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/providers/cpp/polled/unloader/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/providers/cpp/indicationexport/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/providers/cpp/indication/IndicationRepLayer/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/providers/cpp/instance/CIM_Namespace/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/providers/cpp/instance/OpenWBEM_UnitaryComputerSystem/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/providers/cpp/instance/CIM_IndicationSubscription/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/providers/cpp/instance/OpenWBEM_ObjectManager/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/providers/cpp/instance/OW_NameSpace/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/providers/cpp/instance/CIM_IndicationFilter/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/providers/cpp/instance/CIM_NamespaceInManager/Makefile.in
SUBST_FILES.mkdir+=	${WRKSRC}/src/providers/cpp/instance/OpenWBEM_ConfigSettingData/Makefile.in
SUBST_SED.mkdir=        -e "s|\$$(INSTALL_PROGRAM) -d|\$${mkdir_p}|g"
SUBST_MESSAGE.mkdir=    Fixing ${INSTALL_PROGRAM} -d lines (the -s does not interoperate with -d)

CONFIGURE_ARGS.NetBSD+=	ac_cv_func_gethostbyname_r=no

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
