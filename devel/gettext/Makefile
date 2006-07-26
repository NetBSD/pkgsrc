# $NetBSD: Makefile,v 1.74 2006/07/26 06:53:02 adam Exp $

DISTNAME=	gettext-0.14.6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=gettext/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/gettext/gettext.html
COMMENT=	Tools for providing messages in different languages

DEPENDS+=		gettext-m4-0.14.6:../../devel/gettext-m4
DEPENDS+=		gettext-tools-0.14.6:../../devel/gettext-tools
BUILDLINK_API_DEPENDS.gettext+=	gettext-lib>=0.14.5

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
SHLIBTOOL_OVERRIDE=	# empty
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
	cd ${WRKSRC}/gettext-tools && ${MAKE} install-gettextsrcSCRIPTS
	cd ${WRKSRC}/gettext-tools/lib && ${MAKE} install-gettextsrcDATA
	cd ${WRKSRC}/gettext-tools/projects && ${MAKE} install
	cd ${WRKSRC}/gettext-tools/misc && ${MAKE} install
	cd ${WRKSRC}/gettext-tools/src && ${MAKE} install-tcl install-exec-local
	cd ${WRKSRC}/gettext-runtime && ${MAKE} install-gettextsrcDATA
	cd ${WRKSRC}/gettext-tools/intl && ${MAKE} install-exec install-data
	cd ${WRKSRC}/gettext-tools/po && ${MAKE} installdirs-data install-data
	${INSTALL_MAN} ${WRKSRC}/gettext-tools/man/autopoint.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/gettext-tools/man/gettextize.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gettext-asprintf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
