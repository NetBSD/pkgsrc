# $NetBSD: Makefile,v 1.81 2013/01/31 21:45:03 adam Exp $

.include "../../devel/gettext/Makefile.common"

COMMENT=	Tools for providing messages in different languages
LICENSE=	gnu-gpl-v2

DEPENDS+=	gettext-m4-${PKGVERSION_NOREV}{,nb[0-9]*}:../../devel/gettext-m4
DEPENDS+=	gettext-tools-${PKGVERSION_NOREV}{,nb[0-9]*}:../../devel/gettext-tools
BUILDLINK_API_DEPENDS.gettext+=	gettext-lib>=0.18

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
SHLIBTOOL_OVERRIDE=	# empty
CONFIGURE_ARGS+=	--disable-csharp
CONFIGURE_ARGS+=	--without-git
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ENV+=		GCJ= ac_cv_prog_GCJ=
CONFIGURE_ENV+=		HAVE_GCJ_IN_PATH=
CONFIGURE_ENV+=		HAVE_JAVAC_IN_PATH=
CONFIGURE_ENV+=		HAVE_JIKES_IN_PATH=
CONFIGURE_ENV+=		ac_cv_libexpat=no

INSTALLATION_DIRS+=	lib/gettext ${PKGMANDIR}/man1
TEST_TARGET=		check

BROKEN_GETTEXT_DETECTION=	yes
USE_BUILTIN.gettext=	no # force use of pkgsrc gettext-lib

do-install:
	cd ${WRKSRC}/gettext-tools && ${MAKE} install-gettextsrcSCRIPTS DESTDIR=${DESTDIR}
	cd ${WRKSRC}/gettext-tools/projects && ${MAKE} install DESTDIR=${DESTDIR}
	cd ${WRKSRC}/gettext-tools/src && ${MAKE} install-tcl install-exec-local DESTDIR=${DESTDIR}
	cd ${WRKSRC}/gettext-runtime && ${MAKE} install-gettextsrcDATA DESTDIR=${DESTDIR}
	cd ${WRKSRC}/gettext-tools/intl && ${MAKE} install-exec install-data DESTDIR=${DESTDIR}
	cd ${WRKSRC}/gettext-tools/po && ${MAKE} installdirs-data DESTDIR=${DESTDIR}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gettext-asprintf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
