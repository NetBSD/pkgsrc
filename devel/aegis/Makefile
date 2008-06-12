# $NetBSD: Makefile,v 1.17 2008/06/12 02:14:21 joerg Exp $
#

DISTNAME=	aegis-4.22
PKGREVISION=	2
CATEGORIES=	devel scm
MASTER_SITES=	http://aegis.sourceforge.net/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aegis.sourceforge.net/
COMMENT=	Aegis is a transaction base software configuration management system

PKG_DESTDIR_SUPPORT=	user-destdir

EXTRACT_USING=	gtar

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-nlsdir=${_PKGLOCALEDIR:Q}
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		groff gsoelim msgfmt perl:run yacc patch

CONFIGURE_ENV+=		ac_cv_path_PATCH=${TOOLS_PATCH:Q}

EGDIR=			${PREFIX}/share/examples/aegis
INSTALL_MAKE_FLAGS+=	RPM_BUILD_ROOT=${DESTDIR} \
			sysconfdir=${EGDIR}

CONF_FILES+=		${EGDIR}/profile.d/aegis.csh ${PKG_SYSCONFDIR}/profile.d/aegis.csh
CONF_FILES+=		${EGDIR}/profile.d/aegis.sh ${PKG_SYSCONFDIR}/profile.d/aegis.sh

AUTO_MKDIRS=		yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
